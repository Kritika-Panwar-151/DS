#include<stdio.h>
#include<stdlib.h>
#define size 20
#include<ctype.h>

char stack[size];
char postfix[size];
char s[size];

int s_pointer=-1;
int p_pointer=-1;

void push(char op);
char pop();
int isempty();
int isfull();
int pr(char op);

void push(char op)
{
    if(isfull())
    {
        printf("Overflow");
        exit(0);
    }
    else
    {
       stack[++s_pointer]=op;
    }

}
char pop()
{
    return stack[s_pointer--];
}
int isempty()
{
    if(s_pointer==-1)
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
    if(s_pointer==size-1)
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
        return 0;
    else if(op=='+' || op=='-')
        return 1;
    else if(op=='*' || op=='/')
        return 2;
    else
    {
        printf("wrong operator");
        exit(0);
    }

}
void main()
{
    printf("Enter infix expression:");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(isalnum(ch))
        {
            postfix[++p_pointer]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(!isempty() && stack[s_pointer]!='(')
            {
                postfix[++p_pointer]=pop();
            }
            pop();
        }
        else
        {
            while(!isempty() && pr(stack[s_pointer])>=pr(ch))
            {
                postfix[++p_pointer]=pop();
            }
            push(ch);
        }
    }
    while(s_pointer!=-1)
    {
        postfix[++p_pointer]=pop();
    }
    postfix[++p_pointer]='\0';
    printf("Postfix:%s",postfix);
}
