#include <stdio.h>
#include "LinkedList.c"

void main()
{
	int choice;
	Nodeptr first=NULL;
	printf("Enter Choice :\t");
	scanf("%d",&choice);
	while(choice!=4)
	{
		if(choice==1)
		{
			int x,n;
			printf("Enter Number of Nodes : \t");
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				printf("Enter Data of Node %d : \t",i+1);
				scanf("%d",&x);
				first=InsertLast(first,x);
			}
			printf("\nData in List Before Deletion : \n");
			Display(first);
		}

		if(choice==2)
		{
			int key,keysq,count=0;
			printf("Enter Key : \t");
			scanf("%d",&key);
			keysq=key*key;
			DeleteKey(&first,keysq);
		}
		if(choice==3)
		{
			printf("\nData in List After Deletion : \n");
			Display(first);
		}
		printf("\nEnter Choice :\t");
		scanf("%d",&choice);
	}
}