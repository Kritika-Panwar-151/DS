#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;

void insert_front(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=tail=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insert_end(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=tail=newnode;
    }
    else
    {
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}
void insert_position(int val)
{
    struct node *check=head;
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_front(val);
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        if(check==NULL)
        {
            printf("Out of bounds\n");
            return;
        }
        check=check->next;
    }
    if(check->next==NULL)
    {
        insert_end(val);
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=check->next;
    check->next=newnode;
}
void display()
{
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        struct node *check=head;
        while(check!=NULL)
        {
            printf("%d ",check->data);
            check=check->next;
        }
        printf("\n");
    }
}
void main()
{
    int val;
    int op;
    char check='y';
    while(check=='y')
    {
        printf("\nEnter option 1:Insert front 2:Insert end 3:Insert position 4:Display:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter value:");
            scanf("%d",&val);
            insert_front(val);
            break;
        case 2:
            printf("Enter value:");
            scanf("%d",&val);
            insert_end(val);
            break;
        case 3:
            printf("Enter value:");
            scanf("%d",&val);
            insert_position(val);
            break;
        case 4:
            display();
            break;
        default:
            printf("Wrong option");

        }
        printf("Do you want to continue(y/n)?:");
        scanf(" %c",&check);
    }
}
