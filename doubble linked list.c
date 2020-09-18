//Doubble linked list

#include<stdio.h>
#include<string.h>

struct dlist
{
	int info;
	int a[200][200];
	int b[60][550];
	int c[620][520];
	struct list *next;
	struct list *last;
};

void main()
{
	//srand(time(0));
	int inf;
	struct dlist *head,*ptr,*pre;
	head=(struct dlist *)malloc(sizeof(struct dlist));
	ptr=head;
	head->last=NULL;
	int n,num;
	printf("Enter the number of elements to be present in the dlist : ");
	scanf("%d",&num);
	//num=1000;
	for(n=0;n<num;n++)
	{
		printf("Enter the info of node %d : ",n);
		scanf("%d",&inf);
		//inf=rand()%1000;
		ptr->info=inf;
		ptr->next=(struct dlist *)malloc(sizeof(struct dlist));
		pre=ptr;
		ptr=ptr->next;
		ptr->last=pre;
	}
	
	ptr->next=NULL;
	free(ptr);
	ptr=pre;
	printf("\n\n");
	
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->info);
		pre=ptr;
		ptr=ptr->last;
		free(pre);
	}
	//char cmd[100];
	//strcpy(cmd,"E:\\dlist.exe");
	//system(cmd);
}
