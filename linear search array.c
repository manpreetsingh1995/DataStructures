#include<stdio.h>
#include<stdlib.h>
void main()
{
	int ary[1000];
	int i=0,num;
	for(i=0;i<1000;i++)
	{
		ary[i]=i;
	}
	printf("element to be searched : ");
	scanf("%d",&num);
	for(i=0;i<1000;i++)
	{
		if(ary[i]==num)
		{
			printf("%d found at index %d",num,i);
			exit(0);
		}
	}
	printf("Element not found in array");
}

