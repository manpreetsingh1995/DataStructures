//Queue implementation using linked list

#include<stdio.h>

struct node
{
	int info;
	struct node *next;	
};

void add(struct node *ptr)
{
	int info;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}

	printf("Enter the info : ");
	while (scanf("%d",&info)== 0 )
		{
			printf("Pls Enter an integer value !!\n");
			printf("Enter the info : ");
			fflush(stdin);
		}
	ptr->next=(struct node*)malloc(sizeof(struct node));
	ptr=ptr->next;
	ptr->info=info;
	ptr->next=NULL;
}

void del(struct node *ptr)
{
	struct node *rmv;
	rmv=ptr;
	if(ptr->next==NULL)
	{
		printf("Underflow!!!!");
		return;
	}
	ptr=ptr->next;
	rmv->next=ptr->next;
	free(ptr);
}


void output(struct node *ptr)
{
	int i=0;
	printf("\n\nQueue : \n\n");
	if(ptr->next==NULL)
	{
		printf("\nTHERE ARE NO ELEMENTS IN THE QUEUE!!!");
		return;
	}
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		i=ptr->info;
		printf("|%d|    ",i);
	}
}

void main()
{
	struct node *head;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	//head->info=44;
	int opn;
	while(1)
	{
		printf("\n\nPlease Enter an option :\n1   : Add  \n2   : Delete \n99  : exit \n====: ");
		while(scanf("%d",&opn)==0)
		{
			printf("You entered a non integer input :( ");
			printf("\n\nPlease Enter an option :\n1   : Add  \n2   : Delete \n99  : exit \n====: ");
			fflush(stdin);
			//getch();
		}
		
		switch(opn)
		{
			case 1:
				add(head);
				output(head);
				break;
			case 2:
				del(head);
				output(head);
				break;
			case 99:
				printf("Press any key to exit  ");
				getch();
				exit(0);
			default:
				printf("Enter a valid option!!!!");	
		};	
	}
}
