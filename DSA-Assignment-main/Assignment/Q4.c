#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

struct node
{
	char name[100];
    int data1,data2;
    Nodeptr next;
};

Nodeptr getnode()
{
    Nodeptr temp;
    temp = (Nodeptr)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No Free Space");
        return NULL;
    }
    return temp;
}

int isEmpty(Nodeptr list)
{
   if(list==NULL)
    {
        return 1;
    }
   return 0;
}

Nodeptr InsertLast(Nodeptr first,int item1,int item2,char names[])
{
    Nodeptr temp,rear;
    temp=getnode();
    rear=getnode();
    strcpy(temp->name,names);
    temp->data1=item1;
    temp->data2=item2;
    temp->next = NULL;
    rear=first;
    if(isEmpty(first))
    {
        first = temp;
    }
    else
    {
        while(rear->next)
        {
            rear=rear->next;
        }
        rear->next=temp;
    }
    return first;
}

Nodeptr sortlist(Nodeptr first)
{
    Nodeptr temp=first,rear;
    int x,y;
    char ss[100];
    if(isEmpty(temp))
    {
        return NULL;
    }
    else
    {
        while(temp)
        {
            rear=temp->next;
            while(rear)
            {
                if((temp->data1 + temp->data2) > (rear->data1 + rear->data2))
                {
                    x=temp->data1;
                    temp->data1=rear->data1;
                    rear->data1=x;

                    y=temp->data2;
                    temp->data2=rear->data2;
                    rear->data2=y;

                    strcpy(ss,temp->name);
                    strcpy(temp->name,rear->name);
                    strcpy(rear->name,ss);
                }
                rear=rear->next;
            }
            temp=temp->next;
        }
    }
    return first;
}

void Display(Nodeptr first)
{
    Nodeptr temp;
    if(isEmpty(first))
    {
        printf("List is Empty");
    }
    else
    {
        temp=first;
        while(temp)
        {
            printf("%s\t%d\t%d\t\n",temp->name,temp->data1,temp->data2);
            temp=temp->next;
        }
    }
}

void main()
{
	Nodeptr first = NULL,temp;
	first=InsertLast(first,12,45,"Arun");
	first=InsertLast(first,6,89,"Ram");
	first=InsertLast(first,1,60,"Raju");
	Display(first);
	printf("\n");
	first=sortlist(first);
	temp=first;
	temp=temp->next;
	printf("\nDetails of Student with Second Highest Marks are \n");
	printf("%s\t%d\t%d",temp->name,temp->data1,temp->data2);
}