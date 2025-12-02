#include<stdio.h>
#include<stdlib.h>
#define size 20

char stack[size];
int pointer=-1;

void push(char ch);
void pop(char ch);
int isempty();
int isfull();
void main()
{
    char s[size];
    printf("Enter the string of parenthesis:");
    scanf("%s",s);
    char o[]="({[";
    char c[]=")}]";

    for(int i=0;s[i]!='\0';i++)
    {
        for(int j=0;j<3;j++)
        {
            if(s[i]==o[j])
            {
                push(s[i]);
                break;
            }
           else if(s[i]==c[j])
            {
                pop(s[i]);
                break;
            }
        }
    }
    if(pointer==-1)
    {
        printf("Balanced");
    }
    else
    {
        printf("Not Balanced");
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
void push(char ch)
{
    if(isfull())
    {
        printf("Overflow");
        exit(0);
    }
    else
    {
        stack[++pointer]=ch;
    }
}
void pop(char ch)
{
    if(isempty())
    {
        printf("Underflow");
        exit(0);
    }
    else
    {
        if(ch==')' && stack[pointer]=='(')
        {
            --pointer;
        }
        else if(ch=='}' && stack[pointer]=='{')
        {
            --pointer;
        }
        else if(ch==']' && stack[pointer]=='[')
        {
            --pointer;
        }
        else
        {
            printf("Unbalanced");
            exit(0);
        }
    }

}
