//Binary Search Tree

#include<stdio.h>

int space=0;
int height=0,hmax=0;
struct node
{
	struct node *left,*right;
	int info;
};

void search(struct node *ptr,int item)
{
	if(ptr==NULL)
	{
		printf("\n\nElement %d not found in the tree !!",item);
		return;
	}
	if(item==ptr->info)
	{
		printf("Item %d found",item);
		return;
	}	
	else if(item>ptr->info)
		search(ptr->right,item);
	else
		search(ptr->left,item);
}

int min(struct node *ptr)
{
	if(ptr->left==NULL)
		return ptr->info;
	min(ptr->left);
}

int max(struct node *ptr)
{
	if(ptr->right==NULL)
		return ptr->info;
	max(ptr->right);
}

void inorder(struct node *ptr)
{	
	height++;
	if(ptr==NULL)
	{
		height--;
		return;
	}
	if(height>hmax)
		hmax=height;
	inorder(ptr->left);
	printf(" %d ",ptr->info);
	inorder(ptr->right);
	height--;
}

void treeprint(struct node *ptr)
{
	int i;
	space=space+5;
	if(ptr==NULL)
	{
		space=space-5;
		return;
	}
	treeprint(ptr->right);
	for(i=0;i<space;i++)
		printf(" ");
	printf("%d\n",ptr->info);
	treeprint(ptr->left);
	space=space-5;
}

void del(struct node *ptr)
{
	if(ptr==NULL)
		return;
	del(ptr->left);
	del(ptr->right);
	free(ptr);
}

void insert(struct node *ptr,int data)
{
	if(data<ptr->info)
	{
		if(ptr->left==NULL)
		{
			ptr->left=(struct node*)malloc(sizeof(struct node*));
			ptr=ptr->left;
			ptr->info=data;
			ptr->left=NULL;
			ptr->right=NULL;
			return;
		}
		insert(ptr->left,data);
	}
	else if(data==ptr->info)
	{
		return;
	}
	else
	{
		if(ptr->right==NULL)
		{
			ptr->right=(struct node*)malloc(sizeof(struct node*));
			ptr=ptr->right;
			ptr->info=data;
			ptr->left=NULL;
			ptr->right=NULL;
			return;
		}
		insert(ptr->right,data);
	}
}

void main()
{
	int num,data;
	struct node *root=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the number of nodes to be processed : ");
	scanf("%d",&num);
	int i=0;
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			printf("\n\nEnter element %d of binary search tree : ",i+1);
			scanf("%d",&data);
			root->info=data;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			printf("\n\nEnter element %d of binary search tree : ",i+1);
			scanf("%d",&data);
			insert(root,data);
		}
	}
	printf("\n\nBinary Search tree Formed :- \n");
	printf("                                         RIGHT \n");
	printf("                                    ROOT \n");
	printf("                                         LEFT \n\n");
	treeprint(root);
	printf("\n\n\n");
	inorder(root);
	printf("\n\n");
	printf("\n\nMinimum element in the Binary tree = %d",min(root));
	printf("\n\nMaximum element in the Binary tree = %d",max(root));
	printf("\n\nHeight of Binary tree = %d",hmax-1);
	printf("\n\nEnter the element to be searched in the Binary search tree : ");
	scanf("%d",&num);
	search(root,num);
	del(root);
}

