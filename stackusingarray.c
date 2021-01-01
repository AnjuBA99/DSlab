#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
	top=-1;
	printf("Enter the size of stack\t");
	scanf("%d",&n);
	printf("\nStack operations using array\n");
	printf("\n-------------------------------\n");
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
		printf("\nEnter avalid choice\t");
				
		}
				
	}
			
			
}
		while(choice!=4);
		return 0;
}
	void push()
	{  
		if(top>=n-1)
		{
			printf("\tSTACK OVERFLOW\n");
			
		}
		else
		
		{
		printf("\nEnter a value to be pushed\t");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	   }
     }

void pop()
{
	if(top<=-1)
	{
		printf("\nSTACK UNDERFLOW\n");
		
	}
	else
	{
		printf("\n The popped element is %d\t",stack[top]);
		top--;
	}
}
	void display()
	{
		if(top>=0)
		{
			printf("\nThe elements in stack\n");
			for(i=top;i>=0;i--)
	 		printf("\n%d",stack[i]);
			printf("\n Press next choice\t");		}
			else
			{
				printf("\The stack is emppty\n");
			}
	
      }
		
	

	




