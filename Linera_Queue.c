#include<stdio.h>
#define size 5

int queue[size];
int front=-1,rear=-1;

int isempty();
int isfull();
void enqueue(int n);
void dequeue();
void display();
void peek();

int isempty()
{
    if(front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if(rear==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int n)
{
    if(isfull())
    {
        printf("Overflow");
    }
    else if(isempty())
    {
        front++;
        rear++;
        queue[rear]=n;
    }
    else
    {
        rear++;
        queue[rear]=n;
    }
}
void dequeue()
{
    int p;
    if(isempty())
    {
        printf("Underflow");
        return;
    }
    else if(front==rear)
    {
        p=queue[front];
        front=rear=-1;
    }
    else
    {
        p=queue[front];
        front++;
    }
    printf("Removed element:%d",p);
}
void display()
{
    if(isempty())
    {
        printf("Underflow");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}
void peek()
{
    if(isempty())
    {
        printf("Underflow");
    }
    else
    {
        printf("Element at front:%d",queue[front]);
    }
}

void main()
{
    char check='y';
    int op;
    int n;
    while(check=='y')
    {
        printf("ENter 1:Enqueue 2:Dequeue 3:Display 4:Peek:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("Wrong option");
        }
        printf("\nDo you want to continue(y/n)?");
        scanf(" %c",&check);
    }
}
