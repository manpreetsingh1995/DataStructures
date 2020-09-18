#include <stdio.h>

int max;

int a[21];
int b[20];

void merging(int low, int mid, int high)
 {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) 
   {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];


   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] =
	   b[i];
}

void sort(int low, int high) 
{
   int mid;   
   if(low < high)
	{
      mid = (low + high) / 2;
      sort(low, mid);
      sort(mid+1, high);
      merging(low, mid, high);
   }
}

void input(int *ary,int *size)
{
	int num,i;
	printf("Enter the number of elements to be in the List : (less than %d)",*size);
	scanf("%d",&num);
	*size=num;
	if(num<=0||num>*size)
	{	
		printf("Enter a valid number!!!!");
		exit(0);
	}
	for(i=0;i<num;i++)
	{
		printf("\nEnter %d element of the List : ",i+1);
		scanf("%d",&ary[i]);
	}	
}


int main() 
{ 
   int i;
   int size=20;
   input(a,&size);
	max=size-1;
   
   printf("\n\nUnsorted List formed : ");
   for(i=0;i<=max;i++)
		printf("%d ",a[i]);

   sort(0, max);

   printf("\n\n\nList after sorting\n");
   
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}
