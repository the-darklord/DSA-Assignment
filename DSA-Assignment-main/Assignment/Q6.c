#include <stdio.h>
#include "LinkedList.c"
void main()
{
	Nodeptr first=NULL,list1=NULL,list2=NULL;
	first=InsertLast(first,1);
	first=InsertLast(first,2);
	first=InsertLast(first,3);
	first=InsertLast(first,4);
	first=InsertLast(first,5);
	first=InsertLast(first,6);
	printf("Initial List : \n");
	Display(first);
	int x,y;
	while(first)
	{
		x=first->data;
		y=x*x*x;
		if(x%2==0)
		{
			list1=InsertLast(list1,y);
		}
		if(x%2==1)
		{
			list2=InsertLast(list2,y);
		}
		first=first->next;
	}
	printf("\nList 1 : \n");
	Display(list1);
	printf("\nList 2 : \n");
	Display(list2);
}