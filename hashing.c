//Hashing!!!
#include<stdio.h>

#define MAX 20
int ary[MAX]={-1};

void hspr(int key)
{
	int loc;
	loc=key%MAX;
	while(ary[loc]!=-1)
		loc=++loc%MAX;
	ary[loc]=key;
}

void hsearch(int num)
{
	int loc;
	loc=num%MAX;
	while(ary[loc]!=num&&loc<MAX)
	{
		loc++;
		
	}
	if(ary[loc]==num)
		printf("\n\nKEY %d FOUND ",num);
}

void main()
{
	int k;
	for(k=0;k<MAX;k++)
	ary[k]=-1;
	
	int num,j;
	for(j=0;j<5;j++)
	{
		printf("Enter the key to be stored : ");
		fflush(stdin);
		scanf("%d",&num);
		hspr(num);
	//	printf("\n test ok");
	}
	for(num=0;num<MAX;num++)
		printf(" %d ",ary[num]);
		
	printf("\nEnter the key to be searched : ");
	scanf("%d",&num);
	hsearch(num);
}
