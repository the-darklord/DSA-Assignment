#include <stdio.h>
#include "LinkedList.c"

void main()
{
	Nodeptr first=NULL;
	Nodeptr temp,left,right;
	int k,x;
	first=InsertLast(first,3);
	first=InsertLast(first,4);
	first=InsertLast(first,5);
	first=InsertLast(first,6);
	first=InsertLast(first,7);
	printf("Initial List is \n");
	Display(first);
	printf("\n\nEnter k : \t");
	scanf("%d",&k);
	int t=2*k;
	temp=first;
	while(k>0)
	{
		x=DeleteFront(&temp);
		left=InsertLast(temp,x);
		k--;
	}
	printf("\nLeft Rotate : \n");
	Display(left);
	right=left;
	while(t>0)
	{
		x=DeleteLast(&right);
		right=InsertFront(right,x);
		t--;
	}
	printf("\nRight Rotate : \n");
	Display(right);
}