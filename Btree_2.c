//Binary Tree _2
// inorder , preorder , postorder treaversing of binary tree

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
	//free(node);
}

void preorder(struct node *node)
{
	if(node==NULL)
		return;
	printf("  |%d|  ",node->info);
	preorder(node->left);
	preorder(node->right);
	//free(node);
}

void postorder(struct node *node)
{
	if(node==NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf("  |%d|  ",node->info);
	free(node);
}

void main()
{
	int item,num=0,n;
	char ch1,ch;
	struct node *root,*ptr,*prev;
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
			prev=ptr;
		}
		else
		{
			printf("\nEnter the value : ");
			scanf("%d",&item);
			fflush(stdin);
			printf("Enter P to branch from parent or C to branch as child : ");
			scanf("%c",&ch1);
			fflush(stdin);
			printf("\nEnter whether to store on left (l) or right (r) :");
			scanf("%c",&ch);
			if(ch=='l'||ch=='L')
			{
				if(ch1=='p'||ch1=='P')
					ptr=prev;
				ptr->left=(struct node*)malloc(sizeof(struct node));
				prev=ptr;
				ptr=ptr->left;
				ptr->info=item;
				ptr->left=NULL;
				ptr->right=NULL;
			}
			
			else
			{
				if(ch1=='p'||ch1=='P')
					ptr=prev;
				ptr->right=(struct node*)malloc(sizeof(struct node));
				prev=ptr;
				ptr=ptr->right;
				ptr->info=item;
				ptr->left=NULL;
				ptr->right=NULL;
			}
		}
	}
	printf("\n\nInorder   : ");
	inorder(root);
	printf("\n\nPreorder  : ");
	preorder(root);
	printf("\n\nPostorder : ");
	postorder(root);
}
