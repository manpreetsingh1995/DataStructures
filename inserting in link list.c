// link list 
#include<stdio.h>

struct node
{ 
    int data;   
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
	 	printf("%-4d",point->data);
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
 	int info;
	scanf("%d",&info);
	new->data=info;
	new->next=point->next;
	point->next=new;
}


void main()
{
	struct node *end,*head,*root;
	int num,info,count;
	root=(struct node*)malloc(sizeof(struct node));	// 1st node created 
	head=root;
	printf("Enter the numbers to be present in the Linked List : ");
	scanf("%d",&num);

	for(count=1;count<=num;count++)
	{
		printf("Enter %d number value : ",count);
		scanf("%d",&info);
		root->data=info;
		end=root;
		root->next=(struct node*)malloc(sizeof(struct node));
		root=root->next;
	}
	end->next=NULL;
	free(root);
	root=head;
	
	write(head);
	
	printf("\n\nEnter the index at which number is to be inserted : ");
	scanf("%d",&num);
	insert(head,num);
	write(head);
fre(head);	
}
