#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* prev;
    struct node* next;
};
struct node* head=NULL;
struct node* temp=NULL;

void insert()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&(newnode->val));
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL) head=newnode;
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}

void delete_val()
{
    if(head==NULL) printf("Empty List");
    else
    {
        int n;
        int val;
        int flag=0;
        printf("Enter value:");
        scanf("%d",&val);
        temp=head;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==0) printf("Value not found");
        else
        {
            n=temp->val;
            if(temp->prev==NULL)
            {
                head=head->next;
                if(head->next!=NULL) head->prev=NULL;
                free(temp);
            }
            else
            {
                if(temp->next==NULL)
                {
                    temp->prev->next=NULL;
                    free(temp);
                }
                else
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    free(temp);
                }

            }
            printf("Value deleted:%d",n);
        }


    }

}

void display()
{
    if(head==NULL) printf("Empty list");
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
    }
}

void main()
{
    int op;
    char c='y';
    while(c=='y')
    {
        printf("Enter 1:Insert 2:Delete_val 3:Display :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_val();
            break;
        case 3:
            display();
            break;

        default:
            printf("Wrong option");

        }
        printf("\nContinue(y/n):");
        scanf(" %c",&c);
    }
}
