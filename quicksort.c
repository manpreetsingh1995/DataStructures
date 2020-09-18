// Quick Sort

#include<stdio.h>
int count=0;
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

void qsort(int *ary,int l,int r)
{
	int i,j,swp,pivot;
	count++;
	pivot=l;
	i=l+1;
	j=r;
	if(i<j)
	{
	while(i<j)
	{
		if(ary[i]>ary[pivot])
			for(;i<=j;)
			{
				if(ary[j]<ary[pivot])
				{
					swp=ary[j];
					ary[j]=ary[i];
					ary[i]=swp;
					j--;
					break;
				}
				j--;
			}
		i++;
	}
	swp=ary[pivot];
	ary[pivot]=ary[j];
	ary[j]=swp;
	pivot=j;
	//printf("\n%d\n\n",ary[pivot]);
	if((pivot-1)>0)
		qsort(ary,0,pivot-1);
	if((pivot+1)<r)	
		qsort(ary,pivot+1,r);
}	}

void main()
{
	int ary[10];
	int size=10;
	input(ary,&size);
	qsort(ary,0,size-1);
	output(ary,size);
}
