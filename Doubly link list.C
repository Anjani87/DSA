#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next,*pre;
};
struct node*start=NULL;
struct node*create()
{
    struct node*t;
    t=(struct node*)malloc(sizeof(struct node));
    return(t);
}
void addbeg()
{
    struct node*p,*t;
    t=create();
    if(start==NULL)
    {
    
        t->pre=NULL;
        t->next=NULL;
        start=t;
        printf("ENTER THE VALUE OF FRST TO ADD=");
        scanf("%d",&t->data);
    }
    else
    {
        t=create();
        start->pre=t;
        t->next=start;
        t->pre=NULL ;
        start=t;
        printf("ENTER THE VALUE OF NEW NODE");
        scanf("%d",&t->data);
        
    }
}
void display()
{
    struct node*p;
    p=start;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
void addlast()
{
    struct node*p,*t;
    if(start==NULL)
    {
        addbeg();
    }
    else
    {
        t=create();
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
        t->pre=p;
        t->next=NULL;
        printf("enter the vlue of last node=");
        scanf("%d",&t->data);
    }
}
void delbeg()
{
    struct node*p;
    p=start;
    p=p->next;
    p->pre=NULL;
    start=p;
}
void dellast()
{
    struct node*p;
    p=start;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    p->next=NULL;
    
}
void insert()
{
    struct node*p,*t;
    int n,i;
    printf("enter the location=");
    scanf("%d",&n);
    p=start;
    for(i=1;i<n-1;i++)
    {
        p=p->next;
    }
    t=create();
    t->next=p->next;
    t->pre=p;
    p->next=t;
    printf("enter the value of new that should be inserted=");
    scanf("%d",&t->data);
}
void insertafter()
{
    struct node*p,*t;
    int n,i;
    printf("enter the location=");
    scanf("%d",&n);
    p=start;
    for(i=1;i<n;i++)
    {
        p=p->next;
    }
    t=create();
    t->next=p->next;
    t->pre=p;
    p->next=t;
    printf("enter the value of new that should be inserted=");
    scanf("%d",&t->data);
}
void count()
{
    struct node*p;
    int c=0;
    p=start;
    while(p!=NULL)
    {
        c=c+1;
        p=p->next;
    }
    printf("the number of node=%d",c);
}
void main()
{
    addbeg();
    addbeg();
    addbeg();
    addlast();
    addlast();
    delbeg();
    dellast();
    insert();
    insertafter();
    display();
    printf("\n");
    count();
}
