#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20

int stack[size];
int pointer=-1;

void push(int n);
int pop();
int isempty();
int compute(int o1,int o2,char op);

void push(int n)
{
    stack[++pointer]=n;
}
int pop()
{
    if(isempty())
    {
        printf("Worng expression");
        exit(0);
    }
    else
    {
        return stack[pointer--];
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
int compute(int o1,int o2,char op)
{
    if(op=='*')
        return o1*o2;
    else if(op=='/')
        return o1/o2;
    else if(op=='+')
        return o1+o2;
    else if(op=='-')
        return o1-o2;
    else
    {
        printf("Wrong operator");
        exit(0);
    }
}
void main()
{
    char s[size];
    printf("Enter postfix exp:");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else
        {
            int op2=pop();
            int op1=pop();
            int result=compute(op1,op2,ch);
            push(result);
        }
    }
    if(pointer==0)
    {
        printf("Result:%d",stack[pointer]);
    }
    else
    {
        printf("Wrong expression");
    }

}

