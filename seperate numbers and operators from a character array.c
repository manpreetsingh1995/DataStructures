//seperate numbers and operators from a character array
#include<math.h>
#include<stdio.h>
#include<string.h>
int conv(char a)
{
	switch(a)
	{
		case '1':
			return(1);
			break;
		case '2':
			return(2);
			break;
		case '3':
			return(3);
			break;
		case '4':
			return(4);
			break;
		case '5':
			return(5);
			break;
		case '6':
			return(6);
			break;
		case '7':
			return(7);
			break;
		case '8':
			return(8);
			break;
		case '9':
			return(9);
			break;
		case '0':
			return(0);
			break;
		default:
			return(-1);
	};
}

void main()
{
	char expr[40],opr[20];
	int num[20],n=0,o=0,e=0,l,tmp,flag;
	gets(expr);
	for(e=0;e<strlen(expr);e++)
	{
		if(expr[e]==' ')
		{
			if(flag==0)
			{
				num[n++]=tmp;
				tmp=0;
			}
			continue;
		}
		if(conv(expr[e])==-1)
		{
			flag=1;
			opr[o++]=expr[e];
		}
		else
		{	
			flag=0;
			tmp=tmp*10+conv(expr[e]);
		}
	}
	n--;
	for(;--o>=0;)
	{
		switch(opr[o])
		{
			case '+':
				num[n-1]=num[n-1]+num[n];
				n--;
				break;
			case '-':
				num[n-1]=num[n-1]-num[n];
				n--;
				break;
			case '*':
				num[n-1]=num[n-1]*num[n];
				n--;
				break;
			case '/':
				num[n-1]=num[n-1]/num[n];
				n--;
				break;
			case '^':
				num[n-1]=pow(num[n-1],num[n]);
				n--;
				break;
		};
	}
	printf("%d",num[0]);
	getch();
}
