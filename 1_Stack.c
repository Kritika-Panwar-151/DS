

//COMMENTS

#include<stdio.h>
#define size 5
int stack[size];
int pointer=-1;

int isempty();
int isfull();
void push(int n);
void pop();
void display();
void top();
void main()
{
    int n;
    int op;
    char check='y';

    while(check=='y')
    {
        printf("\nEnter option 1:Push 2:Pop 3:Display 4:Top:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Enter element:");
                scanf("%d",&n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                top();
                break;
            default:
                printf("Wrong input");
        }
        printf("Do you wnat to continue:(y/n)?");
        scanf(" %c",&check);
    }


}
int isempty()
{
    if(pointer==-1)
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
    if(pointer==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int n)
{
    if(isfull())
    {
        printf("Overflow");
        printf("\n");
    }
    else
    {
        stack[++pointer]=n;
    }

}
void pop()
{
    if(isempty())
    {
        printf("Underflow");
        printf("\n");
    }
    else
    {
        printf("Popped element:%d",stack[pointer--]);
        printf("\n");
    }

}
void display()
{
    if(isempty())
    {
        printf("Underflow");
        printf("\n");
    }
    else
    {
        for(int i=pointer;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }

}
void top()
{
    if(isempty())
    {
        printf("Underflow");
    }
    else
    {
        printf("Top element:%d",stack[pointer]);
        printf("\n");
    }
}
