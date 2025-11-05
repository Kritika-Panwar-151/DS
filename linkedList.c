#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;//Give adress as null

void push(int val);
void display();
void main()
{

    push(45);
    push(46);
    push(48);
    display();


}

void push(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}
void display()
{
    struct node *check=head;
    do
    {
        printf("\nData:%d",check->data);
        check=check->next;
    }while(check!=NULL);
}
