#include <stdio.h>
#include "LinkedList.c"

void main()
{
	Nodeptr first=NULL,second=NULL;
	first=InsertLast(first,2);
	first=InsertLast(first,4);
	first=InsertLast(first,6);
	first=InsertLast(first,8);
	second=InsertLast(second,3);
	second=InsertLast(second,5);
	second=InsertLast(second,7);
	second=InsertLast(second,9);
	printf("\nList 1 : \n");
	Display(first);
	printf("\nList 2 : \n");
	Display(second);
	printf("\nAfter Merge : \n");
	Nodeptr temp = second;
	while(temp)
	{
		first=InsertLast(first,temp->data);
		temp=temp->next;
	}
	first=sortlist(first);
	Display(first);
}