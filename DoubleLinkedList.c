#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* prev;
    struct node* next;
};

struct node* head=NULL;

void insert();
void delete_pos();
void display();

void insert()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&(newnode->val));
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head!=NULL)
    {
        head->prev=newnode;
        newnode->next=head;

    }
    head=newnode;

}

void delete_pos()
{
    if(head==NULL) printf("Empty List");
    else
    {
        int pos;
        printf("Enter the position:");
        scanf("%d",&pos);
        int n;
        struct node* temp=head;
        if(pos==1)
        {
            n=temp->val;
            head=head->next;
            if(head!=NULL) head->prev=NULL;
            free(temp);
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            n=temp->val;
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
        printf("Removed value:%d",n);

    }

}

void display()
{
    if(head==NULL) printf("Empty List");
    else
    {
        struct node* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
    }
}
void main()
{
    char c='y';
    int op;
    while(c=='y')
    {
        printf("Enter 1:Insert_left 2:Delete_Pos 3:Display :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_pos();
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

