// Banner test

#include<stdio.h>
#include<string.h>

void nputs(char *str,int n)
{
	char s[30];
	strcpy(s,str);
	printf("%c",s[n]);
}

void Dbase(char c,int r)
{
	int tmp;
	tmp=c-'a';
	int i=0;
	char *ary[26];
	ary[0]=" * * ***** ** *";
	ary[1]="**** *** * ****";
	ary[2]="****  *  *  ***";
	ary[3]="** * ** ** *** ";
	ary[4]="****  ** *  ***";
	ary[5]="****  ** *  *  ";
	ary[6]="";
	ary[7]="";
	ary[8]="";
	ary[9]="";
	ary[10]="";
	ary[11]="";
	ary[12]="";
	ary[13]="";
	ary[14]="";
	ary[15]="";
	ary[16]="";
	ary[17]="";
	ary[18]="";
	ary[19]="";
	ary[20]="";
	ary[21]="";
	ary[22]="";
	ary[23]="";
	ary[24]="";
	ary[25]="";
	ary[26]="###############";
	if(tmp>25||tmp<0)
	{	
		for(i=3*r;i<(3*(r+1));i++)
			nputs(ary[26],i);
	}
	else
	{
		for(i=3*r;i<(3*(r+1));i++)
			nputs(ary[tmp],i);
	}
}

void banner(char str[20])
{
	int i=0,j=0;
	//printf("%d",strlen(str));
	for(i=0;i<5;i++)
	{
		for(j=0;j<strlen(str);j++)
			{
				Dbase(str[j],i);
				printf(" ");
			}
		printf("\n");
	}
}

void main()
{
	banner("ab/cdef•");	
}
