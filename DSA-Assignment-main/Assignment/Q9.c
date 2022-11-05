#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Nodeptr;

struct node
{
    char data;
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

Nodeptr InsertLast(Nodeptr first,char item)
{
    Nodeptr temp,rear;
    temp=getnode();
    rear=getnode();
    temp->data = item;
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

void DeleteKey(Nodeptr *first, char key) 
{ 
    Nodeptr temp = *first,prev; 
    while (temp != NULL && temp->data == key) 
    { 
        *first = temp->next;
        free(temp); 
        temp = *first; 
    }  
    while (temp != NULL) 
    { 
        while (temp != NULL && temp->data != key) 
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
            printf("%c\t",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
	Nodeptr first=NULL;
	char str[100];
	printf("Enter Name : \t");
	scanf("%[^\n]",str);
    // gets(str);
	int i=0;
	while(str[i]!='\0')
	{
		first=InsertLast(first,str[i]);
		i++;
	}
	printf("\n");
	Display(first);
	printf("\n");
	printf("Name After removing Vowels : \n");
	DeleteKey(&first,'a');
	DeleteKey(&first,'e');
	DeleteKey(&first,'i');
	DeleteKey(&first,'o');
	DeleteKey(&first,'u');
	DeleteKey(&first,'A');
	DeleteKey(&first,'E');
	DeleteKey(&first,'I');
	DeleteKey(&first,'O');
	DeleteKey(&first,'U');
	printf("\n");
	Display(first);
}