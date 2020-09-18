//Heap tree implementation via array

#include<stdio.h>

void insert(int *heap,int size)
{
	int i,item,num,count=1;
	printf("Enter the no. of elements to be present in heap");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		printf("\nEnter element %d of heap",i);
		scanf("%d",&item);
		if(count==1)
		{
			heap[count++]=num;
		}
		else
		{
			if(heap[count/2]<item)
			{	
				heap[count]=heap[count/2];
				heap[count]=item;
			}
			else
				heap[count]=item;
			count++;
		}
	}
}

void main()
{
	int heap[40],i;
	insert(heap,40);
	for(i=0;i<40;i++)
		printf(" %d ",heap[i]);	
}
