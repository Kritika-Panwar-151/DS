#include<stdio.h>
#define size 5

int queue[size];
int front=-1,rear=-1;

int isempty();
int isfull();
void delete_by_priority();
void display();
void peek();
void insert_by_priority(int n);



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
void insert_by_priority(int n)
{
    if(isfull())
    {
        printf("Overflow");
    }
    else if(isempty())
    {
        front=0;
        rear=0;
        queue[rear]=n;
    }
    else
    {
        //To sort according to priority
        for(int i=front;i<=rear;i++)
        {
            if(n<=queue[i])//Min priority queue
            {

                for(int j=rear;j>=i;j--)
                {
                    queue[j+1]=queue[j];
                }
                queue[i]=n;
                ++rear;
                return;
            }
        }
        queue[++rear]=n;
    }
}
void delete_by_priority()
{
    int n;
    printf("ENter elemenet to delete:");
    scanf("%d",&n);
    if(isempty())
    {
        printf("Underflow");
    }
    else if(n==queue[front] && front==rear)
    {
        front=rear=-1;
        printf("Popped element:%d",n);
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            if(n==queue[i])
            {
                for(int j=i;j<rear;j++)
                {
                    queue[j]=queue[j+1];
                }
                rear--;
                printf("Popped element:%d",n);
                return;
            }
        }
        printf("Element not found");
    }

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
            insert_by_priority(n);
            break;
        case 2:
            delete_by_priority();
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
