#include<stdio.h>

void main()
{
	float eqn[20][20],sol[20][20],x[20]={0.0},sum;
	int num,i,j,k;
	printf("Enter the number of equations and variables (not more han 15) : ");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		for(j=0;j<=num;j++)
		{
			if(j==num)
			{
				printf("Enter C%d : ",i);
				scanf("%f",&eqn[i][j]);
				sol[i][j]=eqn[i][j];
			}
			else
			{
				printf("Enter A%d%d : ",i,j);
				scanf("%f",&eqn[i][j]);
				sol[i][j]=eqn[i][j];
			}
		}
		
	for(i=0;i<num-1;i++)
	{
		for(j=i+1;j<num;j++)
		{
			for(k=i;k<=num;k++)
			{
				sol[j][k]=sol[i][k]*(sol[j][i]/sol[i][i])-sol[j][k];
			}
		}
	}	
		
	/*for(j=0;j<num;j++)
		for(k=0;k<=num;k++)
			printf(" %f ",sol[j][k]);
	*/	
	for(j=num-1;j>=0;j--)
	{
		sum=0;
		for(k=j;k<num;k++)
		{
			if(j!=k)
				sum=sum+sol[j][k]*x[k];
				//sol[j][k]=sol[i][k]*(sol[j][i]*sol[i][i])-sol[j][k];
		}
		x[j]=(sol[j][num]-sum)/sol[j][j];
	}	
	k=0;	
	for(k=0;k<num;k++)	
		printf("\nX%d =  %f",k,x[k]);		
}
