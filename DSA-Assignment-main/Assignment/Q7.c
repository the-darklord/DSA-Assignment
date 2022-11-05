#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *Nodeptr;

struct node
{
    char data[100];
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

Nodeptr InsertLast(Nodeptr first,char item[])
{
    Nodeptr temp,rear;
    temp=getnode();
    rear=getnode();
    strcpy(temp->data,item);
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
            printf("%s\t",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
	Nodeptr first = NULL,PSLIST=NULL,NPSLIST=NULL;
	first=InsertLast(first,"SIRI");
	first=InsertLast(first,"MAM");
	first=InsertLast(first,"lila");
	first=InsertLast(first,"CAC");
	printf("String List is \n");
	Display(first);
	int n,flag;
	char x[100];
	while(first)
	{
        flag=1;
		strcpy(x,first->data);
		n=strlen(x);
		for(int i=0;i<n/2;i++)
		{
			if(x[i]!=x[n-i-1])
            {
                flag=0;
                break;
            }
		}
		if(flag)
		{
			PSLIST=InsertLast(PSLIST,x);
		}
		else
		{
			NPSLIST=InsertLast(NPSLIST,x);
		}
		first=first->next;
	}
	printf("\nPSLIST : \n");
	Display(PSLIST);
	printf("\nNPSLIST : \n");
	Display(NPSLIST);
}