// Queue Implementation using array with exception handling

#include<stdio.h>

void add(int *ary,int *size)
{
	int info;
	printf("\nEnter element to be added : ");
	while(scanf("%d",&info)==0)
	{
		printf("Please enter a valid integer!!!!   :( ");
		printf("\nEnter element to be added : ");
		fflush(stdin);
	}
	int i;
	ary[*size]=info;
	*size=*size+1;
}

void del(int *ary,int *size)
{
	if(*size<1)
	{
		printf("\n\nUNDERFLOW!!!!!");
		//printf("\nPROGRAM WILL EXIT NOW!!!!");
		return;
	}
	int i;
	for(i=0;i<*size;i++)
		ary[i]=ary[i+1];
	*size=*size-1;
}

void input(int *ary,int *size)
{
	int num,i;
	printf("Enter the number of elements to be in the Queue : (less than %d)",*size);
	scanf("%d",&num);
	*size=num;
	if(num<=0||num>*size)
	{	
		printf("Enter a valid number!!!!");
		
		exit(0);
	}
	int count=1;
	for(i=0;i<num;i++)
	{
		printf("\nEnter %d element of the Queue : ",count++);
		while (scanf("%d",&ary[i]) == 0 )
		{
			printf("Pls Enter an integer value !!\n");
			fflush(stdin);
			
		}
	}	
}

void output(int *ary,int size)
{
	int i=size;
	printf("\n\n\nQueue : \n\n");
	if(i<1)
	{
		printf("\nTHERE ARE NO ELEMENTS IN THE QUEUE!!!");
		return;
	}
	for(i=0;i<size;i++)
	{
		if(i==0)
			printf("|%d|",ary[i]);
		else
			printf("----|%d|",ary[i]);
	}
}

void operation(int *ary,int *size)
{
	int opn;
	printf("\n\nPlease Enter an option :\n1   : Add  \n2   : Delete \n99  : exit \n====: ");
	while(scanf("%d",&opn)==0)
	{
		printf("You entered a non integer input :( ");
		printf("\n\nPlease Enter an option :\n1   : Add  \n2   : Delete \n99  : exit \n====: ");
		fflush(stdin);
		//getch();
	}
	
	switch(opn)
	{
		case 1:
			add(ary,size);
			output(ary,*size);
			operation(ary,size);
			break;
		case 2:
			del(ary,size);
			output(ary,*size);
			operation(ary,size);
			break;
		case 99:
			printf("Press any key to exit  ");
			getch();
			exit(0);
		default:
			printf("Enter a valid option!!!!");	
			operation(ary,size);
	};	
}

void main()
{
	int ary[10];
	int size=10;
	input(ary,&size);
	output(ary,size);
	operation(ary,&size);
}
