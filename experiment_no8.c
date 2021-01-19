/*
  NAME:Khan Farhan Nadeem 
  ROLLNO: 19CO27
  COURSE: Data Structure
  Experiment No 8: Implementation of Circular Linked list

*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//#pragma pack(1)
struct CLL         //self referencial structure
{
    int data;       //if int takes 4 bytes then this data would take 4 bytes
    struct CLL *next;  //4 bytes
};

struct CLL *insertAtEnd(struct CLL *h, int d)
{
    struct CLL *p,*tmp;
    p=(struct CLL *)malloc(sizeof(struct CLL));
    if(p==NULL)
    {
        printf("\nNot Enough memory.");
        return h;
    }
    p->data=d;
    
    if(h==NULL)
        h=p;
    else
    {
        tmp=h;
        while(tmp->next!=h)    //changed for CLL
            tmp=tmp->next;
        tmp->next=p;
    }
    p->next=h;          //changed for CLL
    return h;
    
}

struct CLL *insertAtBeg(struct CLL *h, int d)
{
    struct CLL *p,*tmp;
    p=(struct CLL *)malloc(sizeof(struct CLL));
    if(p==NULL)
    {
        printf("\nNot Enough memory.");
        return h;
    }
    p->data=d;
    if(h==NULL)
        p->next=p;
    else
    {
        p->next=h;
        tmp=h;
        while(tmp->next!=h)
            tmp=tmp->next;
        tmp->next=p;
    }
    h=p;
       
    return h;
    
}

struct CLL *insertAfter(struct CLL *h,int d,int k)
{
    struct CLL *p,*tmp;
    if(h==NULL)
    return h;
    p=(struct CLL*)malloc(sizeof(struct CLL));
    if(p==NULL)
    {
        printf("\nNot enough memory..");
        return h;
    }
    p->data=d;
    p->next=NULL;
    tmp=h;
    while(tmp->next!=h && tmp->data!=k)
    tmp=tmp->next;
    if(tmp->data!=k)
    tmp=tmp->next;
    if(tmp==h && tmp->data!=k)
    {
    printf("\nGiven Key data does not exist..");
    }
    else
    {
        p->next=tmp->next;
        tmp->next=p;
    }
    
    return h;
}

void display(struct CLL *h)
{
    if(h==NULL)
        printf("\nLinked List is Empty.");
    else
    {
        struct CLL *tmp;
        int n=0;
        tmp=h;
        printf("\n\n\tCircular Linked List Content:");
        printf("\n\t\tAddress\tData\tNext");
        do
        {
            printf("\n\t\t%x\t%d\t%x",tmp,tmp->data,tmp->next);
            tmp=tmp->next;
            n++;
        }while(tmp!=h); //changed for CLL
        printf("\n\tSize of Linked List: %d bytes.",n*sizeof(struct CLL));
        //printf("\nSize of Int: %d and Size of Pointer: %d",sizeof(int),sizeof(struct CLL *));
        //printf("\n\tSize of Structure: %d bytes.",sizeof(struct CLL));
    }
    
}

struct CLL *removelast(struct CLL *h)
{
    struct CLL *tmp,*prev;
    if(h==NULL)
        printf("\nList is Empty.");
    else
    {
        tmp=h;  //i=0;
        prev=tmp;
        while(tmp->next!=h)  //changed //while(i!=5)
        {               
            prev=tmp;           //j=i;
            tmp=tmp->next;      //i=i+1;
        }
        if(h->next==h)      //changed
        h=NULL;
        else
        prev->next=h;   //changed
        free(tmp); 
        printf("\nLast Node Removed.");
    }
    return h;
}

struct CLL *removeGiven(struct CLL *h,int k)
{
    struct CLL *tmp,*prev;
    if(h==NULL)
        printf("\nList is Empty.");
    else
    {
        tmp=h;  //i=0;
        prev=tmp;
        while(tmp->next!=h && tmp->data!=k)  //while(i!=5)
        {               
            prev=tmp;           //j=i;
            tmp=tmp->next;      //i=i+1;
        }
        if(tmp->data!=k)
        {
        prev=tmp;
        tmp=tmp->next;
        }
        if(tmp==h && tmp->data!=k)
        {
        printf("\nGiven Node does not exist.");
        return h;
        }
        if(h==tmp && h->next!=h)
        {
        //h=h->next;
        prev=h;
        while(prev->next!=h)
        prev=prev->next;
        h=h->next;
        prev->next=h;
        }
        else
        {
        if(h->next==h)
        h=NULL;
        else
        prev->next=tmp->next;
        }
        free(tmp); 
        printf("\nGiven Node Removed.");
    }
    return h;
}


struct CLL *removeBefore(struct CLL *h,int k)
{
    struct CLL *tmp,*prev,*q;
    if(h==NULL)
    {
        printf("\nList is Empty.");
        return h;
    }
    tmp=h;
    prev=tmp;
    while(tmp->next!=h && tmp->data!=k)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp->data!=k)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    
    if(tmp==h && tmp->data==k)
    {
        printf("\nNo node before the first node.");
        return h;
    }
    if(tmp==h && tmp->data!=k)
    {
        printf("\nGiven Node does not exist.");
        return h;
    }
//prev is pointing to a node to be deleted.
    tmp=h;
    while(tmp->next!=prev)
        tmp=tmp->next;
//tmp is pointing to a node before/previous to the node to be deleted.
    if(prev==h)
    {
    //h=h->next;
    //traverse
    q=h;
    while(q->next!=h)
        q=q->next;
    h=h->next;
    q->next=h;
    }
    else
    tmp->next=prev->next;
    prev->next=NULL;
    free(prev);
    return h;
}

int main()
{
struct CLL *head;
int ch,d,k;
head=NULL;
while(1)
{
printf("\n\n\n\t\t\tMENU");
printf("\n1. Insert.\n2. Insert Begin.\n3. Insert After.\n4. Remove.\n5. Remove Given.\n6. Remove Before.\n7. Display.\n8. Exit.");
printf("\n\tEnter Your Choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\tEnter Data : ");
scanf("%d",&d);
head=insertAtEnd(head,d);
break;
case 2:
printf("\n\tEnter Data : ");
scanf("%d",&d);
//printf("\n\tEnter Key Data : ");
//scanf("%d",&k);

head=insertAtBeg(head,d);

break;

case 3:
printf("\n\tEnter Data : ");
scanf("%d",&d);
printf("\n\tEnter Key Data : ");
scanf("%d",&k);

head=insertAfter(head,d,k);
//head=removelast(head);
//head=removefirst(head);
break;
case 4:
head=removelast(head);
break;
case 5:
printf("\n\tEnter Key : ");
scanf("%d",&d);
head=removeGiven(head,d);
break;
case 6:
printf("\n\tEnter Key : ");
scanf("%d",&d);
head=removeBefore(head,d);
break;

case 7:
display(head);
break;
case 8:
//exit(0);
return 0;
break;
default:
printf("\n\t\tPlease enter correct choice....");
}
}
return 0;
}