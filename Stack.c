// Stack Implementation using array

#include<stdio.h>

void push(int *ary,int *size)
{
	int info;
	if(*size>10)
	{
		printf("Maximum Limit of Stack reached!!!");
		getch();
		return;
	}
	printf("\nEnter element to be pushed : ");
	while(scanf("%d",&info)==0)
	{
		printf("\nPlease enter a valid integer :(  !!");
		printf("\nEnter element to be pushed : ");
		fflush(stdin);
	}
	ary[*size]=info;
	*size=*size+1;
}

void pop(int *ary,int *size)
{
	if(*size<1)
	{
		printf("Underflow!!!!!");
		getch();
		return;
	}
	*size=*size-1;
	
}

void input(int *ary,int *size)
{
	int num,i;
	printf("Enter the number of elements to be in the Stack : (less than %d)",*size);
	scanf("%d",&num);
	*size=num;
	if(num<=0||num>*size)
	{	
		printf("Enter a valid number!!!!");
		exit(0);
	}
	int count=1;
	for(i=0;i<*size;i++)
	{
		printf("\nEnter %d element of the Stack : ",count);
		while(scanf("%d",&ary[i])==0)
		{
			printf("\nPlease enter a valid integer :(  !!");
			printf("\nEnter %d element of the Stack : ",count);
			fflush(stdin);
		}
		count++;
	}	
}

void output(int *ary,int size)
{
	int i;
	system("cls");
	printf("\n\t\t\t\t      Stack \n");
	if(size<1)
	{
		printf("\t\t\t\tSTACK IS EMPTY!!!");
		getch();
		return;
	}
	for(i=size-1;i>=0;i--)
	{
		printf("\t\t\t\t|_______________|\n");
		printf("\t\t\t\t|%8d\t|\n",ary[i]);
		printf("\t\t\t\t|_______________|\n");
	}
}

void operation(int *ary,int *size)
{
	int opn;
	printf("\n\nEnter 1 : PUSH  2 : POP    or 99 to exit :\n");
	while(scanf("%d",&opn)==0)
	{
		printf("You entered a non integer input :( ");
		printf("\n\nEnter 1 : Add  2 : Delete    or 99 to exit :\n");
		fflush(stdin);
	}
	switch(opn)
	{
		case 1:
			push(ary,size);
			output(ary,*size);
			operation(ary,size);
			break;
		case 2:
			pop(ary,size);
			output(ary,*size);
			operation(ary,size);
			break;
		case 99:
			printf("Press any key to exit ");
			getch();
			exit(0);
		default:
			printf("Enter a valid option!!!!");	
			operation(ary,size);
	};	
}

void main()
{
	int ary[10],opn;
	int size=10;
	input(ary,&size);
	output(ary,size);
	operation(ary,&size);
}
