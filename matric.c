// Matrix 
#include<stdio.h>
#include<stdlib.h>

void check(int row,int col)
{
	if(row>20||col>20)
	{	
		printf("Overflow!!! enter value less than 20");
		exit(0);
	}
	if(row<1||col<1)
	{	
		printf("Enter value greater than 0");
		exit(0);
	}
}

void matrixtrp(int a[20][20],int b[20][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			b[j][i]=a[i][j];
}

void matrixin(int a[20][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\nEnter element [%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}

void matrixout(int a[20][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %4d ",a[i][j]);
		}
		printf("\n");
	}
}

void matrixsum(int a[20][20],int b[20][20],int c[20][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			c[i][j]=a[i][j]+b[i][j];
	}
}

void matrixdiff(int a[20][20],int b[20][20],int c[20][20],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			c[i][j]=a[i][j]-b[i][j];
	}
}

void matrixmul(int a[20][20],int b[20][20],int c[20][20],int row,int col,int row2,int col2)
{
	int i,j,k,sum=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col2;j++)
			{
				sum=0;
				for(k=0;k<col;k++)
				{
					sum+=a[i][k]*b[k][j];
				}
				c[i][j]=sum;	
			}
	}
}

void main()
{
	int a[20][20]={0};
	int b[20][20]={0};
	int c[20][20]={0};
	int row,tmp,col,opn;
	int row2,col2;
	printf("1 - Addition of 2 matrices\n2 - Subtraction of two matrices\n3 - Transpose a matrix\n4 - Multiply 2 matrices");
	printf("\n : ");
	scanf("%d",&opn);
	//opn=1;
	switch(opn)
	{
		case 1:
			printf("For Adding two matrices number of rows and columns in both matrices must be same\n");
			printf("Enter the number of rows in matrix (<20) : ");
			scanf("%d",&row);
			//row=15;
			printf("\nEnter the number of columns in matrix (<20) : ");
			scanf("%d",&col);
			//col=15;
			check(row,col);
			printf("\n Element Elements of first matrix : =>\n");
			matrixin(a,row,col);
			printf("\n Element Elements of second matrix : =>\n");
			matrixin(b,row,col);
			matrixsum(a,b,c,row,col);
			system("cls");
			printf("\n Sum Matrix =>\n");
			matrixout(a,row,col);
			for(tmp=0;tmp<(col*4)-(col-1);tmp++)
				printf(" ");
			printf("+\n");
			matrixout(b,row,col);
			for(tmp=0;tmp<(col*4)-(col-1);tmp++)
				printf(" ");
			printf("=\n");
			matrixout(c,row,col);
			break;
		case 2:
			printf("For Subtracting two matrices number of rows and columns in both matrices must be same\n");
			printf("Enter the number of rows in matrix (<20): ");
			scanf("%d",&row);
			printf("\nEnter the number of columns in matrix (<20) : ");
			scanf("%d",&col);
			check(row,col);
			printf("\n Element Elements of first matrix : =>\n");
			matrixin(a,row,col);
			printf("\n Element Elements of second matrix : =>\n");
			matrixin(b,row,col);
			matrixdiff(a,b,c,row,col);
			system("cls");
			printf("\n Subtraction Matrix =>\n");
			matrixout(a,row,col);
			for(tmp=0;tmp<(col*4)-(col-1);tmp++)
				printf(" ");
			printf("-\n");
			matrixout(b,row,col);
			for(tmp=0;tmp<(col*4)-(col-1);tmp++)
				printf(" ");
			printf("=   \n");
			matrixout(c,row,col);
			break;
		case 3:
			//--printf("For Adding two matrices number of rows and columns in both matrices must be same\n");
			printf("Enter the number of rows in matrix (<20) : ");
			scanf("%d",&row);
			printf("\nEnter the number of columns in matrix (<20) : ");
			scanf("%d",&col);
			check(row,col);
			printf("\n Element Elements of the matrix : =>\n");
			matrixin(a,row,col);
			matrixtrp(a,b,row,col);
			printf("\n\n Original matrix =>\n\n");
			matrixout(a,row,col);
			printf("\n\n Transpose matrix =>\n\n");
			matrixout(b,row,col);
			break;
		case 4:
			printf("Enter the number of rows in first matrix (<20) : ");
			scanf("%d",&row);
			printf("\nEnter the number of columns in first matrix (<20) : ");
			scanf("%d",&col);
			printf("Enter the number of rows in second matrix (<20) : ");
			scanf("%d",&row2);
			printf("\nEnter the number of columns in second matrix (<20) : ");
			scanf("%d",&col2);
			//checkmul(col,row2);
			printf("\n Element Elements of first matrix : =>\n");
			matrixin(a,row,col);
			printf("\n Element Elements of second matrix : =>\n");
			matrixin(b,row2,col2);
			matrixmul(a,b,c,row,col,row2,col2);
			system("cls");
			printf("\n\n Matrix Multiplication=>\n\n");
			matrixout(a,row,col);
			for(tmp=0;tmp<(col*4)-(col-1);tmp++)
				printf(" ");
			printf("X\n");
			matrixout(b,row2,col2);
			for(tmp=0;tmp<(col*4)-(col-1);tmp++)
				printf(" ");
			printf("=   \n");
			matrixout(c,row,col2);
		default:
		printf("Bye ");	
	};
}
