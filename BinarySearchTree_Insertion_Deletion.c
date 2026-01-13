#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* left;
    struct node* right;
};

void insert(struct node* root,struct node* temp)
{
    if(temp->val>root->val)
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

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
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

void postorder(struct node* root)
{
    if(root!=NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->val);
    }
}

struct node* createnode()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter value:");
    scanf("%d",&newnode->val);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* minnode(struct node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;

}
struct node* delete(struct node* root,int val)
{
    if(root==NULL) return root;
    else if(val>root->val) root->right=delete(root->right,val);
    else if(val<root->val) root->left=delete(root->left,val);
    else
    {
        //NO child
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        //right child
        else if(root->left==NULL)
        {
            struct node* temp=root;
            root=root->right;
            free(temp);
        }
        //left child
        else if(root->right==NULL)
        {
            struct node* temp=root;
            root=root->left;
            free(temp);
        }
        //Two child
        else
        {
            struct node* temp=minnode(root->right);
            root->val=temp->val;
            root->right=delete(root->right,temp->val);
        }
    }
    return root;
}
void main()
{
    struct node* root=NULL;
    struct node* temp=NULL;
    char c='y';
    int op;
    int val;

    do
    {
        printf("ENter: 1:Insert 2:Delete:");
        scanf("%d",&op);
        if(op==1)
        {
            temp=createnode();
            if(root==NULL) root=temp;
            else insert(root,temp);
        }
        else
        {
            printf("ENter value to delete:");
            scanf("%d",&val);
            root=delete(root,val);
        }

        printf("\nContinue(y/n)?");
        scanf(" %c",&c);
    }while(c=='y');


    /**
    do
    {
        temp=createnode();
        if(root==NULL) root=temp;
        else insert(root,temp);
        printf("\nContinue(y/n)?");
        scanf(" %c",&c);
    }while(c=='y');
    **/
    printf("\nPreorder:");
    preorder(root);

    printf("\nInorder:");
    inorder(root);

    printf("\nPostorder:");
    postorder(root);
}

