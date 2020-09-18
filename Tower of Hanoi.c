//Tower of hanoi

#include<stdio.h>

void hanoi(int n,char x,char y,char z)
{
    if (n == 1) 
    { 
        printf("\n Move disk 1 from peg %c to peg %c", x, y); 
        return; 
    } 
    hanoi(n-1, x, z, y); 
    printf("\n Move disk %d from peg %c to peg %c", n, x, y); 
    hanoi(n-1, z, y, x); 
}

void main()
{
	int dnum;
	printf("Enter the number of disks in the problem : ");
	scanf("%d",&dnum);
	if(dnum<1)
	{
		printf("Enter a valid number !!!!");
		getch();
		exit(0);	
	}
	printf("\nMoving from Peg X to Peg Y using auxilary peg Z\n\n");
	printf("\n   |     |     |");
	printf("\n   |     |     |");
	printf("\n   |     |     |");
	printf("\n   -------------");
	printf("\n   X     Y     Z\n");
	hanoi(dnum,'X','Y','Z');
	
}
