// linked list with 2 nodes ...............without loop!!
#include<stdio.h>

struct node
{ 
    int data;   
    struct Node *next; 
};
 
void main()
{
	struct node *head,*root,*tmp,*rmv;
	root=(struct node*)malloc(sizeof(struct node));	// 1st node created 
	
	tmp=root;
	root->data=22;
	root->next=(struct node*)malloc(sizeof(struct node)); // 2nd node created 
	root=root->next;
	root->data=44;
	printf("%d",tmp->data);
	rmv=tmp;
	tmp=tmp->next;
	free(rmv);	//1st node removed
	printf("\n");
	printf("%d",tmp->data);
	free(tmp);	//2nd node removed
}
