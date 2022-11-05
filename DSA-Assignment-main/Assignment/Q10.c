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

void DeleteKey(Nodeptr *first, char key[]) 
{ 
    Nodeptr temp = *first,prev; 
    temp =  temp->next; 
    while (temp != NULL && strcmp(temp->data,key)==0)
    { 
        *first = temp->next;
        free(temp); 
        temp = *first; 
    }  
    while (temp != NULL) 
    { 
        while (temp != NULL && strcmp(temp->data,key)!=0) 
        { 
            prev = temp; 
            temp = temp->next; 
        } 
        if (temp == NULL) return; 
        prev->next = temp->next; 
        free(temp);  
        temp = prev->next; 
    }
}

int Search(Nodeptr first,char str[])
{
	Nodeptr temp=first;
	int count=0;
	while(temp)
	{
		if(strcmp(str,temp->data)==0)
		{
			count++;
		}
		temp=temp->next;
	}
	return count;
}

void main()
{
	Nodeptr first = NULL;
	first=InsertLast(first,"raj");
	first=InsertLast(first,"Aryan");
	first=InsertLast(first,"Anirudh");
	first=InsertLast(first,"Aryan");
	first=InsertLast(first,"prasad");
	first=InsertLast(first,"Aryan");
	first=InsertLast(first,"Anirudh");
	printf("Initial List \n");
	Display(first);
	Nodeptr temp = first;
	printf("\n");
	while(temp)
	{
		int x=Search(temp,temp->data);
		printf("%s,%d \t",temp->data,x);
		DeleteKey(&temp,temp->data);
		temp=temp->next;
	}
}