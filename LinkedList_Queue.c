#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
};
struct node* head=NULL;

void enqueue();
void dequeue();
void display();

void enqueue()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&(newnode->val));
    newnode->next=NULL;
    if(head==NULL) head=newnode;
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void dequeue()
{
    if(head==NULL) printf("Empty list");
    else
    {
        struct node* temp=head;
        head=head->next;
        printf("Value dequeued:%d",temp->val);
        free(temp);
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
        printf("Enter 1:Enqueue 2:Dequeue 3:Display :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
