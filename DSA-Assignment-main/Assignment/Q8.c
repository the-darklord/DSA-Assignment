#include <stdio.h>
#include "LinkedList.c"

void main()
{
	Nodeptr first=NULL,list1=NULL,list2=NULL;
	first=InsertLast(first,1);
	first=InsertLast(first,2);
	first=InsertLast(first,6);
	first=InsertLast(first,4);
	first=InsertLast(first,8);
	printf("Initial List : \n");
	Display(first);
	int count=0,x;
	while(first)
	{
		count++;
		x=first->data;
		if(count%2==1)
		{
			list1=InsertLast(list1,x);
		}
		else
		{
			list2=InsertLast(list2,x);
		}
		first=first->next;
	}
	printf("\nList 1 : \n");
	Display(list1);
	printf("\nList 2 : \n");
	Display(list2);
}