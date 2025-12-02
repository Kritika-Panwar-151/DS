#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;
struct node *temp1=NULL;
struct node *temp2=NULL;

void insert_front(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=tail=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void insert_end(int val)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=tail=newnode;
    }
    else
    {
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}
void insert_position(int val)
{
    struct node *check=head;
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_front(val);
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        if(check==NULL)
        {
            printf("Out of bounds\n");
            return;
        }
        check=check->next;
    }
    if(check->next==NULL)
    {
        insert_end(val);
        return;
    }
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=check->next;
    check->next=newnode;
}
void display()
{
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        struct node *check=head;
        while(check!=NULL)
        {
            printf("%d ",check->data);
            check=check->next;
        }
        printf("\n");
    }
}
void delete_beg()
{
    if(head==NULL)
    {
        printf("Empty List");
    }
    else
    {
        if(head==tail)
        {
            free(head);
            head=tail=NULL;
        }
        else
        {
            temp1=head;
            head=head->next;
            free(temp1);
        }

    }

}
void delete_end()
{
    if(head==NULL)
    {
        printf("Empty List");
    }
    else
    {

        if(head==tail)
        {
            free(head);
            head=tail=NULL;
        }
        else
        {
            temp1=head;
            while(temp1->next!=tail)
            {
                temp1=temp1->next;
            }
            temp2=tail;
            tail=temp1;
            tail->next=NULL;
            free(temp2);
        }

    }

}
void delete_pos()
{
    if(head==NULL)
    {
        printf("Empty List");
    }
    else
    {
        int pos;
        printf("Enter the position:");
        scanf("%d",&pos);
        if(pos==1)
        {
            delete_beg();
            return;
        }
        temp1=NULL;
        temp2=head;
        for(int i=1;i<pos;i++)
        {
            if(temp2==NULL)
            {
                printf("Out of bounds");
                return;
            }
            temp1=temp2;
            temp2=temp2->next;
        }

        temp1->next=temp2->next;
        free(temp2);
        if(temp1->next==NULL)
        {
            tail=temp1;
        }
    }

}


void main()
{
    int val;
    int op;
    char check='y';
    while(check=='y')
    {
        printf("\nEnter option 1:Insert front 2:Insert end 3:Insert position 4:Delete front 5:Delete end 6:Delete position 7:Display:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter value:");
            scanf("%d",&val);
            insert_front(val);
            break;
        case 2:
            printf("Enter value:");
            scanf("%d",&val);
            insert_end(val);
            break;
        case 3:
            printf("Enter value:");
            scanf("%d",&val);
            insert_position(val);
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            delete_pos();
            break;
        case 7:
            display();
            break;
        default:
            printf("Wrong option");

        }
        printf("Do you want to continue(y/n)?:");
        scanf(" %c",&check);
    }
}

