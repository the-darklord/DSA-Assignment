#include <stdio.h>
#include "LinkedList.c"

void main()
{
	int n,first=0,last=1,count=2,temp;
	Nodeptr list=NULL;
	list=InsertLast(list,first);
	list=InsertLast(list,last);
	printf("Enter Number of Fibonacci Numbers : \t");
	scanf("%d",&n);
	while(count<n)
	{	temp=first;
		first=last;
		last=last+temp;
		list=InsertLast(list,last);
		count++;
	}
	printf("Fibonacci Series is \n");
	Display(list);
}