// Infix to Postfix

#include<stdio.h>
#include<string.h>

int pre(char c)
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

void output(char *ary,int size)
{
	int i;
	printf("\n      Expression \n");
	for(i=0;i<size;i++)
		printf("%c",ary[i]);
}


void main()
{
	char ch,stk[60],expr[60];
	int i=0,s=0,e=0;
	printf("Enter the equation (one element each time) : \n ");
	for(;i<60;i++)
	{
		scanf("%c",&ch);
		if(ch=='~')
			break;
			
			
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
		{
			if(ch==')')
			{
				while(stk[--s]!='(')
				{
					expr[e++]=stk[s];
				}
				continue;
			}
			
		if(pre(stk[s-1])>=pre(ch))
		{
			expr[e++]=stk[--s];
			stk[s++]=ch;
			continue;
		}
		
			stk[s++]=ch;
		}
		else
		{
			expr[e++]=ch;
		}
	}

	output(expr,e);
}

