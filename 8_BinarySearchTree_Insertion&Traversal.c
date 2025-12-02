#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* left;
    struct node* right;
    int val;
};

struct node* createnode()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value:");
    scanf("%d",&(newnode->val));
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insert(struct node* root,struct node* temp)
{
    if(root->val<temp->val)
    {
        if(root->right!=NULL) insert(root->right,temp);
        else root->right=temp;
    }
    else
    {
        if(root->left!=NULL) insert(root->left,temp);
        else root->left=temp;
    }
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->val);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
    }
}

void main()
{
    struct node* temp=NULL;
    struct node* root=NULL;
    char c='y';
    do
    {
        temp=createnode();
        if(root==NULL) root=temp;
        else insert(root,temp);
        printf("(y/n):");
        scanf(" %c",&c);
    }while(c=='y');

    printf("\nPreorder:");
    preorder(root);

    printf("\nInorder:");
    inorder(root);

    printf("\nPostorder:");
    postorder(root);
}
