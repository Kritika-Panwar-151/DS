#include<stdio.h>
int pointer=-1;
char check='y';
int stacks[];
void push(int size);
void pop();
void peek();
void display();
void main()
{
    int size,choice;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    stacks[size];
    while(check=='y')
    {
        printf("Enter your choice 1:Push 2:Pop 3:Peek 4:Display :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push(size);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Wrong option selected");
        }
        printf("\nDo you want to continue(y/n)");
        scanf(" %c",&check);
    }
}
void push(int size)
{
    int element;
    if(pointer+1==size)
    {
        printf("Stack is full");
    }
    else
    {
        printf("Enter the element:");
        scanf("%d",&element);
        stacks[++pointer]=element;
    }
}
void pop()
{
    if(pointer==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Popped element: %d",stacks[pointer]);
        --pointer;
    }

}
void peek()
{
    if(pointer==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top element: %d",stacks[pointer]);
    }
}
void display()
{
    if(pointer==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Array elements:");
        for(int i=0;i<=pointer;i++)
        {
            printf(" %d",stacks[i]);
        }
    }
}
