#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;//Give adress as null
struct node *tail=NULL;
void insert_front(int val);
void insert_end(int val);
void insert_position(int val);
void display();
void main()
{
    int val;
    int op;
    char c='y';
    while(c=='y')
    {
        printf("Enter option: 1:Insert Front 2:Insert End 3:Insert Position 4:Display:");
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
        printf("\nDo you want to continue?(y/n):");
        scanf(" %c",&c);
    }

}

void insert_front(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=tail=newnode;
        newnode->data=val;
        newnode->next=NULL;
    }
    else
    {
        newnode->data=val;
        newnode->next=head;
        head=newnode;
    }


}
void insert_end(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        head=tail=newnode;
        newnode->data=val;
        newnode->next=NULL;
    }
    else
    {
        newnode->data=val;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }

}
void insert_position(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    struct node *traverse=head;
    int p;
    printf("Enter the position:");
    scanf("%d",&p);
    if(p==1)
    {
        insert_front(val);
        return;
    }
    for(int i=1;i<p-1;i++)
    {
        if(traverse==NULL)
        {
            printf("Out of bounds");
            return;
        }
        traverse=traverse->next;


    }
    if(traverse->next==NULL)
    {
        insert_end(val);
    }
    else
    {
        newnode->data=val;
        newnode->next=traverse->next;
        traverse->next=newnode;
    }

}

void display()
{
    struct node *check=head;
    if(check==NULL)
    {
        printf("Empty list");
    }
    else
    {
        while(check!=NULL)
        {
            printf("\nData:%d",check->data);
            check=check->next;
        }
    }
}

