#include<stdio.h>
void main()
{
	int ary[20],tmp;
	int j=0,index,tnum=20;
	for(j=0;j<20;j++)
	{
		ary[j]=j;
		printf("Element at index %d = %d\n",j,ary[j]);
	}	
	printf("Enter the index at which element is to be deleted [from array of 20 elements]: ");
	scanf("%d",&index);
	if(index>19||index<0)
	{
		printf("Out os scope of array");
		exit(0);
	}
	else
	{
		tnum=tnum-1;
		for(j=index;j<tnum;j++)
		{
			ary[j]=ary[j+1];
		}	
	}	
	printf("\n\n Printing the array : - >>");
	
		for(j=0;j<tnum;j++)
			printf("\n Element %d = %d",j,ary[j]);
}
