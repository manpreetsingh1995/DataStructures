#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	srand(time(0));
	int input,i;
	float n;
	printf("------------------------------------------------------\n");
	printf(" |  Inputs     \t         Complexity\n");
	printf("------------------------------------------------------\n");
	printf(" |\t\t Binary Search \t  Linear Search  \n");
	printf("------------------------------------------------------\n");
	for(i=0;i<20;i++)
	{
		input=rand();
		if(input>0)
		{
			n=log2(input);
			printf(" | %-10d  |     %f \t|\t%-10d|\n",input,n,(input+1/2);
		}
		else
		{
			printf("Enter a valid input");
			exit(0);
		}
	}
}
