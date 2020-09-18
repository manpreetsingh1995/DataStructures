#include<stdio.h>

struct node
{ 
    int data;   
    struct Node *next; 
};
 
void main()
{
	struct node *head,*root,*rmv,*end;
	int num,info,count;
	root=(struct node*)malloc(sizeof(struct node));	// 1st node created 
	head=root;
	printf("Enter the numbers to be present in the Linked List : ");
	scanf("%d",&num);
	rmv=root;
	
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
	printf("Linked List-->>\n\n");
	while(root!=NULL)
	{
		printf("%4d",(root->data));
		root=root->next;
	}	
	int opn=0;
	//printf("Null");
	
	printf("\n\nChoose one of the following options : \n");
	printf("1 - Insert in begining\n");
	printf("2 - Insert in End : ");
	scanf("%d",&opn);
	
	switch(opn)
	{
		case 1:
			rmv=(struct node*)malloc(sizeof(struct node));
			rmv->next=head;
			printf("\n Enter the data of the node to be inserted :");
			scanf("%d",&info);
			rmv->data=info;
			head=rmv;
			break;
		case 2:
			rmv=(struct node*)malloc(sizeof(struct node));
			rmv->next=NULL;
			printf("\n Enter the data of the node to be inserted :");
			scanf("%d",&info);
			//printf("%d",info);
			rmv->data=info;
			end->next=rmv;
			break;
		default:
			break;	
	};
	printf("\n\nLinked List-->>\n\n");
	root=head;
	while(root!=NULL)
	{
		printf("%4d",(root->data));
		root=root->next;
	}	
	getch();
	
	
	for(count=1;count<=num;count++)
	{
		rmv=root;
		root=root->next;
		free(rmv);
	}	
	getch();
}
