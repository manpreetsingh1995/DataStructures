// Infix to Postfix

#include<stdio.h>

int pre(char c)		// function to return the priority of an operator
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

void main()
{
	char ch[60], stk[60], expr[60];
	int l,i=0,s=0,e=0,brq=0;
	printf("Enter the equation : ");
	gets(ch);
	l=strlen(ch);	// l = number of characters in the equation
	//printf("%d",l);
	for(i=0;i<l;i++)
	{
		if(ch[i]=='(')
		{
			stk[s++]=ch[i];
			continue;
		}
		if(ch[i]==')')
		{
			while(stk[--s]!='(')
			{
				expr[e++]=stk[s];
			}
			//s--;
			brq++;
			continue;
		}
		if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='^')
		{
			if(pre(stk[s-1])<0)
			{
				stk[s++]=ch[i];		
				continue;
			}
			else if(pre(ch[i])<=pre(stk[s-1]))
			{
				expr[e++]=stk[--s];
				stk[s++]=ch[i];
				continue;
			}	
			stk[s++]=ch[i];
			continue;	
		}
		
		expr[e++]=ch[i];
	}
	printf("Post FIX equivalent of %s : ",ch);
	for(i=0;i<(l-brq*2);i++)
		printf("%c",(expr[i]));
	//puts(expr);
}

