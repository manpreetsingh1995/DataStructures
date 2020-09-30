// inorder traversing of binary tree

#include<stdio.h>

struct node
{
	struct node *left,*right;
	int info;
};

void inorder(struct node *node)
{
	if(node==NULL)
		return;
	inorder(node->left);
	printf("  |%d|  ",node->info);
	inorder(node->right);
}

void preorder(struct node* node)
{
	if(node==NULL)
		return;
	printf("  |%d|   ",node->info);
	preorder(node->left);
	preorder(node->right);
}

void postorder(struct node* node)
{
	if(node==NULL)
		return;
	preorder(node->left);
	preorder(node->right);
        printf("  |%d|   ",node->info);
}
	

void main()
{
	int item,num=0,n;
	char ch;
	struct node *root,*ptr;
	root=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number of nodes to be present in the binary tree : ");
	scanf("%d",&n);
	for(num=0;num<n;num++)
	{
		if(num==0)
		{
			printf("\nEnter the value : ");
			scanf("%d",&item);
			root->info=item;
			root->left=NULL;
			root->right=NULL;
			ptr=root;
		}
		else
		{
			printf("\nEnter the value : ");
			scanf("%d",&item);
			fflush(stdin);
			
			printf("\nEnter whether to store on left (l) or right (r) :");
			scanf("%c",&ch);
			if(ch=='l'||ch=='L')
			{
				ptr->left=(struct node*)malloc(sizeof(struct node));
				ptr=ptr->left;
				ptr->info=item;
				ptr->left=NULL;
				ptr->right=NULL;
			}
			
			else
			{
				ptr->right=(struct node*)malloc(sizeof(struct node));
				ptr=ptr->right;
				ptr->info=item;
				ptr->left=NULL;
				ptr->right=NULL;
			}
		}
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
}
