#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 15
char stacks[size];
char postfix[size];
char s[size];
int pointer=-1;
int i=-1;

void push(char e);
char pop();
int isempty();
int isfull();
int pr(char op);

void main()
{

    char check='y';
    while(check=='y')
    {
        pointer=-1;
        i=-1;
        printf("\nEnter the equation:");
        scanf("%s",s);
        for(int j=0;s[j]!='\0';j++)
        {
            char ch=s[j];
            if(isalnum(ch))
            {
                postfix[++i]=ch;
            }
            else if(ch=='(')
            {
                push(ch);
            }
            else if(ch==')')
            {
                while(stacks[pointer]!='(')
                {
                    postfix[++i]=pop();
                }
                pop();
            }
            else
            {
                while(!isempty() && pr(stacks[pointer])>=pr(ch))
                {
                    postfix[++i]=pop();
                }
                push(ch);
            }

        }
        while(pointer!=-1)
            {
                postfix[++i]=pop();
            }
        postfix[++i]='\0';
        printf("Postfix: %s",postfix);
        printf("\nDo you want to continue(y/n):");
        scanf(" %c",&check);
    }
}

void push(char e)
{
    if(!isfull())
    {
        stacks[++pointer]=e;
    }
    else
    {
        printf("Overflow");
        exit(0);
    }
}
char pop()
{
    if(!isempty())
    {
        return stacks[pointer--];
    }
    else
    {
        printf("Underflow");
        exit(0);
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
int pr(char op)
{
    if(op=='(' || op==')')
    {
        return -1;
    }
    else if(op=='+' || op=='-')
    {
        return 0;
    }
    else if(op=='*' || op=='/')
    {
        return 1;
    }
    else
    {
        printf("Wrong operator");
        exit(0);
    }
}
