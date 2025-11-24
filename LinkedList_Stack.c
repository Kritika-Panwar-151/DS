#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node* next;
};
struct node* head=NULL;

void push();
void pop();
void display();
void top();

void push()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("nEnter value:");
    scanf("%d",&(newnode->val));
    newnode->next=head;
    head=newnode;
}

void pop()
{
    if(head==NULL) printf("Empty stack");
    else
    {
        struct node* temp=head;
        printf("Value popped:%d",temp->val);
        head=head->next;
        free(temp);
    }
}

void display()
{
    if(head==NULL) printf("Empty stack");
    else
    {
        struct node* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
    }
}

void top()
{
    if(head==NULL) printf("Empty stack");
    else printf("%d ",head->val);
}

void main()
{
    char c='y';
    int op;
    while(c=='y')
    {
        printf("Enter 1:Push 2:Pop 3:Display 4:Top :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            push();
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
            printf("Wrong option");
        }
        printf("\nContinue(y/n):");
        scanf(" %c",&c);
    }

}
