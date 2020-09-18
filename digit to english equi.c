//convert Digits to English Equivalent
#include<stdio.h>
#include<string.h>
void convert(int a)
{
	switch(a)
	{
		case 1:
			printf("one ");
			break;
		case 2:
			printf("two ");
			break;
		case 3:
			printf("three ");
			break;
		case 4:
			printf("four ");
			break;
		case 5:
			printf("five ");
			break;
		case 6:
			printf("six ");
			break;
		case 7:
			printf("seven ");
			break;
		case 8:
			printf("eight ");
			break;
		case 9:
			printf("nine ");
			break;
		case 0:
			printf("zero ");
			break;
		default:
			printf("default ");
			break;
	};
}
void main()
{
	int num,rem[20],count=0;
	printf("Enter the number : ");
	scanf("%d",&num);
	printf("\n\n");
	while(num!=0)
	{
		rem[count++]=num%10;
		num=num/10;
	}
	for(--count;count>=0;count--)
	{
		convert(rem[count]);
	}
}
