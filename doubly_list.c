#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	struct node *next;
	int data;
};
struct node *head;
void insertion_begining();
void insertion_last();
void insertion_specified();
void deletion_begining();
void deletion_last();
void deletion_specified();
void display();
void search();
int main()
{
	int choice=0;
	while(choice!=9)
	{printf("\n    Main Menu  \n");
	printf("Choose one option");
	printf("\n 1.Insert in begining\n2.Insert last\n3.Insert at any specified position\n4.delete from begining");
	printf("\n5.Delete from last \n6.delete the node after a given node\n7.search\n8.display\n9.Exit\n");
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insertion_begining();
			break;
		case 2:
			insertion_last();
			break;
		case 3:
			insertion_specified();
			break;	
		case 4:
			deletion_begining();
			break;
		case 5:
			deletion_last();
			break;
		case 6:
			deletion_specified();
			break;
		case 7:
			search();
			break;	
		case 8:
			display();
			break;
		case 9:
			exit(0);
			break;	
		default:
		printf("Please enter valid choice!!");		
			
         }
	   }
	
	  }
	 void insertion_begining()
	 {
	 struct node *ptr;
	 int item;
	 ptr=(struct node *)malloc(sizeof(struct node));
	 if(ptr==NULL)
	   {
	 	printf("\n OVERFLOW");
		 }	
	 	else
	 	{
	 	printf("\n Enter item value:");
		 scanf("%d",&item);
		 if(head==NULL)
		 {
		 	ptr->next=NULL;
		 	ptr->prev=NULL;
		 	ptr->data=item;
		 	head=ptr;
		 	
		 }
		 else
		 {
		 	ptr->data=item;
		 	ptr->prev=NULL;
		 	ptr->next=head;
		 	head->prev=ptr;
		 	head=ptr;
		 }
		 
		 printf("\n Node inserted");
		 	
		 }
	 	
	  }
	  void insertion_last()
	  {
	  struct node *ptr,*temp;
	  int item;
	  ptr=(struct node *)malloc(sizeof(struct node));
	  
	  if(ptr==NULL)
	  {
	  	printf("\n OVERFLOW");
	  }
	  else
	  {
	  	printf("\n Enter value:");
	  	scanf("%d",&item);
	  	ptr->data=item;
	  	if(head==NULL)
	  	{
	  		ptr->next==NULL;
	  		ptr->prev=NULL;
	  		head=ptr;
	  		
	    } 
	    else
	    {
	    	temp=head;
	    	while(temp->next!=NULL)
	    	{
	    		temp=temp->next;
	    		
			}
			temp->next=ptr;
			ptr->prev=temp;
			ptr->next=NULL;
			
		}
	  }
	  printf("\n Node Inserted");
	  }
	  void insertion_specified()
	  {
	  	struct node *ptr,*temp;
	  	int item,loc,i;
	  	ptr=(struct node *)malloc(sizeof(struct node));
	  	if(ptr==NULL)
	  	{
	  		printf("\n OVERFLOW");
		  }
		  else
		  {
		  	temp=head;
		  	printf("Enter the location");
		  	scanf("%d",&loc);
		  	for(i=0;i<loc;i++)
		  	{
		  		temp=temp->next;
		  		if(temp==NULL)
		  		{
		  			printf("\n There are less than %d elements",loc);
		  			return;
				  }
		  		
			  }
			  printf("Enter value:");
			  scanf("%d",&item);
			  ptr->data=item;
			  ptr->next=temp->next;
			  ptr->prev=temp;
			  temp->next=ptr;
			  temp->next->prev=ptr;
			  printf("\nNode inserted\n");
		  }
	  	
	   }
	 void deletion_begining()
	 {
	 	struct node *ptr;
	 	if(head==NULL)
	 	{
	 		printf("\n UNDERFLOW");
		 }
		 else if(head->next==NULL)
		 {
		 	head=NULL;
		 	free(head);
		 	printf("\n Node deleted\n");
		 	
		 }
		 else
		 {
		 	ptr=head;
		 	head=head->next;
		 	head->prev=NULL;
		 	free(ptr);
		 	printf("\n Node deleted\n");
		 }
	  } 
	  void deletion_last()
	  {
	  	struct node *ptr;
	  	if(head==NULL)
	  	{
	  		printf("\n UNDERFLOW");
	  		
		  }
		  else if(head->next==NULL)
		  {
		  	head=NULL;
		  	free(head);
		  	printf("\nNode deleted\n");
		  }
		  else
		  {
		  ptr=head;
		  if(ptr->next!=NULL)
		  {
		  	ptr=ptr->next;
		  	
			  }	
			  ptr->prev->next=NULL;
			  free(ptr);
			  printf("\n Node deleted\n");
		  }
	  }
	  void deletion_specified()
	  {
	  	struct node *ptr,*temp;
	  	int val;
	  	printf("\nEnter the data after which the node is to be deleted:");
	  	scanf("%d",&val);
	  	ptr=head;
	  	while(ptr->data!=val)
	  	ptr=ptr->next;
	  	if(ptr->next==NULL)
	  	{
		  printf("\n Can't delete\n");
		  
	  	
		  }
		  else if(ptr->next->next==NULL)
		  {
		  	ptr->next=NULL;
		  	
		  }
		  else 
		  {
		  temp=ptr->next;
		  ptr->next=temp->next;
		  temp->next->prev=ptr;
		  free(temp);
		  printf("\nNode deleted\n");	
		  }
	  }
	  void display()
	  {
	  	struct node *ptr;
	  	printf("\nPrinting values");
		  ptr=head;
		  while(ptr!=NULL)
        {
		printf("%d\n",ptr->data);
        ptr=ptr->next;
		}
		}
		void search()
		{
			struct node *ptr;
			int item,i=0,flag;
			ptr=head;
			if(ptr==NULL)
			{
				printf("\n Empty list\n");
			}
			else
			{
				printf("\n Enter thenitem to be searched\n");
				scanf("%d",&item);
				while(ptr!=NULL)
				{
					if(ptr->data==item)
					{
						printf("\n Item found at location %d",i+1);
						flag=0;
						break;
					}
					else
					{
						flag=1;
					}
					i++;
					ptr=ptr->next;
				}
				if(flag==1)
				{
					printf("\n Item not found\n");
				}
			}
		}
		
		
		
		
			  
	  
	  
	  
	  
	  
	  
	  
	  






	

