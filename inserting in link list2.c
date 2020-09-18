// link list 
#include<stdio.h>
#include<string.h>
struct node
{ 
    char data[20];   
    struct Node *next; 
};
 
void fre(struct node *point)
 {
	struct node *tmp;
 	while(point!=NULL)
	{
 		tmp=point;
 		free(tmp);
		point=point->next;
 	}
}
 
 void write(struct node *point)
 {
 	int count=1;
 	while(point!=NULL)
	{
	 	//printf("%-4d",count);
	 	puts(point->data);
	 	point=point->next;
 	}
}

void insert(struct node *point,int n)
 {
 	int count=1;
 	for(count=1;count<n-1;count++)
	{
	 	point=point->next;
 	}
 	struct node *new=(struct node*)malloc(sizeof(struct node));
 	printf("\nEnter the element to be inserted : ");
 	char info[20];
	scanf("%s",info);
	strcpy(new->data,info);
	new->next=point->next;
	point->next=new;
}


void main()
{
	struct node *end,*head,*root;
	int num,count;
	char info[20];
	root=(struct node*)malloc(sizeof(struct node));	// 1st node created 
	head=root;
	printf("Enter the numbers to be present in the Linked List : ");
	scanf("%d",&num);

	for(count=1;count<=num;count++)
	{
		printf("Enter %d string : ",count);
		scanf("%s",info);
		strcpy(root->data,info);
		end=root;
		root->next=(struct node*)malloc(sizeof(struct node));
		root=root->next;
	}
	end->next=NULL;
	free(root);
	root=head;
	
	write(head);
	
	printf("Enter the index at which number is to be inserted : ");
	scanf("%d",&num);
	insert(head,num);
	write(head);
fre(head);	
}
