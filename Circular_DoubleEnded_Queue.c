#include<stdio.h>
#define size 5

int queue[size];
int front=-1,rear=-1;

int isempty();
int isfull();
void f_enqueue(int n);
void r_enqueue(int n);
void f_dequeue();
void r_dequeue();
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
    if((rear+1)%size==front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void f_enqueue(int n)
{
    if(isfull())
    {
        printf("Overflow");
    }
    else if(isempty())
    {
        front++;
        rear++;
        queue[front]=n;
    }
    else
    {
        front=(front-1+size)%size;
        queue[front]=n;
    }
}
void r_enqueue(int n)
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
        rear=(rear+1)%size;
        queue[rear]=n;
    }
}
void f_dequeue()
{
    int p;
    if(isempty())
    {
        printf("Undeflow");
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
        front=(front+1)%size;
    }
    printf("Popped element:%d",p);
}
void r_dequeue()
{
    int p;
    if(isempty())
    {
        printf("Undeflow");
        return;
    }
    else if(front==rear)
    {
        p=queue[rear];
        front=rear=-1;
    }
    else
    {
        p=queue[rear];
        rear=(rear-1+size)%size;
    }
    printf("Popped element:%d",p);
}
void display()
{
    if(isempty())
    {
        printf("Undeflow");
    }
    else
    {
        int f=front;
        int r=rear;
        do
        {
            printf("%d ",queue[f]);
            f=(f+1)%size;
        }while(f!=(rear+1)%size);
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
        printf("ENter 1:F_Enqueue 2:R_Enqueue 3:F_Dequeue 4:R_Dequeue 5:Display 6:Peek:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&n);
            f_enqueue(n);
            break;
        case 2:
            printf("Enter element:");
            scanf("%d",&n);
            r_enqueue(n);
            break;
        case 3:
            f_dequeue();
            break;
        case 4:
            r_dequeue();
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        default:
            printf("Wrong option");
        }
        printf("\nDo you want to continue(y/n)?");
        scanf(" %c",&check);
    }
}

