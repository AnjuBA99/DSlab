#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
    {
      int data;
    struct node *next;
   };
   struct node *top;
void main()
{
	int choice;
	printf("\n Stack operations using linkedlist\n");
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
	do
	{
		printf("\nEnter the choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			{
			
				push();
				break;
				
	        }
		    case 2:
	        	{
			
		    	pop();
		    	break;
	        	}
		    case 3:
	    	{
				display();
				break;
	    	}
	    	case 4:
	    	{
			  printf("\nExit ");
		    	break;
	    	}
	        default:
	    	{
	        	printf("\nEnter a valid choice\t");
				
	     	}
				
	}
			
			
}
		while(choice!=4);
		return 0;
}
void push()
{
	int x;
	struct node *current=(struct node*)malloc(sizeof(struct node));
	if(current==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("Enter the value");
		scanf("%d",&x);
		if(top==NULL)
		{
		current->data=x;
		current->next=NULL;
		top=current;
		}
		else
		{
			current->data=x;
			current->next=top;
			top=current;
		}
		printf("Item pushed");
	}
}
void pop()
{
	int item;
	struct node *current;
	if(top==NULL)
	{
		printf("UNDERFLOW");
	}
	else
	{
		item=top->data;
		current=top;
		top=top->next;
		free(current);
		printf("Item popped");
	}
}
	void display()
	{
		struct node *current;
		current=top;
		if(current==NULL)
		{
			printf("Stack is empty\n");
		}
		else
		{
			printf("Printing stack elements\n");
			while (current!=NULL)
			{
			printf("%d\n",current->data);
			current=current->next;	
			}
		}
	}


	 
	 	
