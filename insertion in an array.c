#include<stdio.h>
void main()
{
	int ary[20],tmp;
	int j=0,num,index,tnum=20;
	for(j=0;j<19;j++)
	{
		ary[j]=j;
		printf("Element at index %d = %d\n",j,ary[j]);
	}
	printf("Enter the element to be inserted in array : ");
	scanf("%d",&num);	
	printf("Enter the index at which element is to be inserted : ");
	scanf("%d",&index);
	if(index>19)
	{
		printf("Out os scope of array");
		exit(0);
	}
	else
	{
		tnum=tnum+1;
		for(j=tnum;j>index;j--)
		{
			ary[j]=ary[j-1];
		}	
		ary[index]=num;
	}	
	printf("\n\n Printing the array : - >>");
	
		for(j=0;j<tnum;j++)
			printf("\n Element %d = %d",j,ary[j]);
}
