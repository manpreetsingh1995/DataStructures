// Bubble Sorting and Selection sort

#include<stdio.h>

void input(int *ary,int *size)
{
	int num,i;
	printf("Enter the number of elements to be in the List : (less than %d)",*size);
	scanf("%d",&num);
	*size=num;
	if(num<=0||num>*size)
	{	
		printf("Enter a valid number!!!!");
		exit(0);
	}
	for(i=0;i<num;i++)
	{
		printf("\nEnter %d element of the List : ",i+1);
		scanf("%d",&ary[i]);
	}	
}

void output(int *ary,int size)
{
	int i;
	printf("\n List :\n");
	for(i=0;i<size;i++)
	{
		printf("  %d  ",ary[i]);
	}
}

void bsort(int *ary,int size)
{
	int i,j,swp;
	for(i=0;i<size-1;i++)
	{

		for(j=0;j<((size-1)-i);j++)
		{
			if(ary[j]>ary[j+1])	
			{
				swp=ary[j];
				ary[j]=ary[j+1];
				ary[j+1]=swp;
			}
		
		}
	}
}

void selsort(int *ary,int size)
{
	int i,j,swp,max;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(ary[i]>ary[j])	
			{
				swp=ary[j];
				ary[j]=ary[i];
				ary[i]=swp;
			}
		}
	}
}


void main()
{
	int ary[10];
	int size=10;
	input(ary,&size);
	bsort(ary,size);
	output(ary,size);

}
