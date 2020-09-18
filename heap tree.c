//Heap Tree

#include<stdio.h>

int space=0;
struct node
{
	struct node *left,*right;
	int full;
	int info;
};

void del(struct node *ptr)
{
	if(ptr==NULL)
		return;
	del(ptr->left);
	del(ptr->right);
	free(ptr);
}


int heightl(struct node *ptr)
{
	int tmp;
	static int hl=0;
	if(ptr==NULL)
	{
		tmp= hl;
		hl=0;
		return tmp;
	}
	else
	{
		hl++;
		heightl(ptr->left);
	}
}

int heightr(struct node *ptr)
{
	int tmp;
	static int hr=0;
	if(ptr==NULL)
	{
		tmp= hr;
		hr=0;
		return tmp;
	}
	else
	{
		hr++;
		heightr(ptr->right);
	}
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

void insert(struct node *ptr,int data)
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
	else if(ptr->right==NULL)
	{
		ptr->right=(struct node*)malloc(sizeof(struct node*));
		ptr=ptr->right;
		ptr->info=data;
		ptr->left=NULL;
		ptr->right=NULL;
		return;
	}
	else
	{
		ptr->full=1;
		if(heightl(ptr)<=heightr(ptr))
			insert(ptr->left,data);
		else
			insert(ptr->right,data);
		return;
	}
}

int main()
{
	int num,data;
	struct node *root=(struct node*)malloc(sizeof(struct node*)),*ptr;
	ptr=root;
	printf("Enter the number of nodes to be processed : ");
	scanf("%d",&num);
	int i=0;
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			printf("\n\nEnter element %d of heap tree : ",i+1);
			scanf("%d",&data);
			root->info=data;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			printf("\n\nEnter element %d of heap tree : ",i+1);
			scanf("%d",&data);
			insert(root,data);
		}
		
	}	
	treeprint(ptr);
	del(ptr);
}
