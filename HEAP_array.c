//Heap tree implementation via array

#include<stdio.h>
#include<math.h>
int insert(int *heap,int size)
{
	int i,item,num;
	printf("Enter the no. of elements to be present in heap : ");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("\nEnter element %d of heap : ",i);
		scanf("%d",&item);
		if(i==1)
		{
			heap[i]=item;
		}
		else
		{
			heap[i]=item;
			reheap(heap,i);
		}
	}
	return(size);
}

void reheap(int *heap,int size)
{
	int tmp;
	if((size/2)==0)
	{
		return;
	}
	else if(heap[size]>heap[size/2])
	{
		tmp=heap[size];
		heap[size]=heap[size/2];
		heap[size/2]=tmp;
	}
	reheap(heap,--size);
}

void htreeout(int *heap,int size)
{
	int i,j,k=1,l=0,space,m;
	for(i=1;i<=size+1;)
	{
		i=pow(2,i);
		l++;
	}
	space=pow(2,l);
	for(i=0;i<=l;i++)
	{
		printf("\n");
		for(m=0;m<space;m++)
			printf(" ");
		for(j=k;j<pow(2,i+1);j++)
		{
			if(heap[k]!=0)
				printf("%d",heap[k++]);
			else
				printf(" ");
			for(m=0;m<space;m++)
				printf(" ");
		}
		space=space/2;
	}
}

void main()
{
	int heap[40]={0},i,size;
	size=insert(heap,40);
	htreeout(heap,size);
	printf("\n\n Enter the element to be added : ");
	scanf("%d",&i);
	heap[++size]=i;
	reheap(heap,size);
	htreeout(heap,size);
	
	printf("\n\n Enter the index no of element to be deleted : ");
	scanf("%d",&i);
	heap[i]=0;
	reheap(heap,size);
	htreeout(heap,size);
	
}
