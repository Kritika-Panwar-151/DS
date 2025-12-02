#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* temp=NULL;

void push()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&(newnode->val));
    newnode->next=head1;
    head1=newnode;
}

void pop()
{
    if(head1==NULL) printf("Empty stack");
    else
    {
        printf("Value popped:%d",head1->val);
        temp=head1;
        head1=head1->next;
        free(temp);
    }
}

void stack_display()
{
    if(head1==NULL) printf("Empty stack");
    else
    {
        temp=head1;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
    }
}

void enqueue()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value:");
    scanf("%d",&(newnode->val));
    newnode->next=NULL;
    if(head2==NULL) head2=newnode;
    else
    {
        temp=head2;
        while(temp->next=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void dequeue()
{
    if(head2==NULL) printf("Empty queue");
    else
    {
        printf("Value dequeued:%d",head2->val);
        temp=head2;
        head2=head2->next;
        free(temp);
    }
}

void queue_display()
{
    if(head2==NULL) printf("Empty stack");
    else
    {
        temp=head2;
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
        printf("Enter 1:Push 2:Pop 3:Stack_Display 4:Peek 5:Enqueue 6:Dequeue 7:Queue_Display :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            stack_display();
            break;
        case 4:
            if(head1==NULL) printf("Empty stack");
            else printf("%d",head1->val);
            break;
        case 5:
            enqueue();
            break;
        case 6:
            dequeue();
            break;
        case 7:
            queue_display();
            break;
        default:
            printf("Wrong option");

        }
        printf("\nContinue(y/n):");
        scanf(" %c",&c);
    }
}
