#include<stdio.h>
#include<stdlib.h>
	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
	
	};
main()
{
struct node *start=NULL;
struct node *last,*temp,*newnode;
int i,n,data;
printf("Enter the number of elements");
scanf("%d",&n);

for(i=1;i<=n;i++)
{
	
	struct node *newnode=(struct node *)malloc(sizeof(struct node*));
	printf("\nEnter element");
		scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	if(start==NULL)
	{
		newnode->prev=NULL;
		start=newnode;
		last=newnode;
	}
	else
	{
	last->next=newnode;
	newnode->prev=last;
	last=newnode;
 }

printf("\n Linked list in forward direction\n");
temp=start;
if(temp==NULL)
	printf("\nList is empty");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
printf("\n Linked list in backward direction");
temp=last;
if(temp==NULL)

	printf("\nList is empty");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}

}
return 0;
}
 

	
	
	
	
	
	
	
	
	
	
	
	
	
