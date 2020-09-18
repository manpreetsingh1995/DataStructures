// linked list with user defined number of nodes ...............without loop!!
#include<stdio.h>

struct node
{ 
    int data;   
    struct Node *next; 
};
 
 


 
void main()
{
	struct node *head,*root,*rmv;
	int num,info,count;
	root=(struct node*)malloc(sizeof(struct node));	// 1st node created 
	head=root;
	printf("Enter the numbers to be present in he Linked List : ");
	scanf("%d",&num);
	rmv=root;
	for(count=1;count<=num;count++)
	{
		printf("Enter %d number value : ",count);
		scanf("%d",&info);
		root->data=info;
		root->next=(struct node*)malloc(sizeof(struct node));
		root=root->next;
	}
	root=head;
	for(count=1;count<=num;count++)
	{
		rmv=root;
		printf("INFO of Node %d in the Linked List = : %d\n",count,(root->data));
		root=root->next;
		free(rmv);
	}	
	system("pause");
}
