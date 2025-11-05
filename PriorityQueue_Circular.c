#include<stdio.h>
#define size 5

int queue[size];
int front=-1,rear=-1;

int isempty();
int isfull();
void insert_by_priority(int n);
void delete_by_priority();
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
        int f=front;
        int r=rear;
        do
        {
            if(n<=queue[f])
            {
                for(int j=rear;j!=(f-1+size)%size;j=(j-1+size)%size)
                {
                    queue[(j+1)%size]=queue[j];
                }
                rear=(rear+1)%size;
                queue[f]=n;
                return;
            }
            f=(f+1)%size;
        }while(f!=(r+1)%size);
        rear=(rear+1)%size;
        queue[rear]=n;
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
        int f=front;
        int r=rear;
        do
        {
            if(n==queue[f])
            {
                for(int j=f;j!=rear;j=(j+1)%size)
                {
                    queue[j]=queue[(j+1)%size];
                }
                rear=(rear-1+size)%size;
                printf("Popped element:%d",n);
                return;
            }
            f=(f+1)%size;
        }while(f!=(r+1)%size);

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
        int f=front;
        int r=rear;
        do
        {
            printf("%d ",queue[f]);
            f=(f+1)%size;
        }while(f!=(r+1)%size);
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
