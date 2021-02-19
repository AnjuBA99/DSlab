#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
   struct node
   {
	struct node *rep;
	struct node *next;
	int data;
   }*heads[50],*tails[50];
static int countRoot=0;
void makeSet(int x)
 {
	struct node *new=(struct node*)malloc(sizeof(struct node));
  	new->rep=new;
	new->next=NULL;
	new->data=x;
	heads[countRoot]=new;
	tails[countRoot++]=new;
   }
	struct node* find(int a)
	  {
	  	int i;
	  	struct node *temp=(struct node*)malloc(sizeof(struct node));
	  	for(i=0;i<countRoot;i++)
	  	{
	  		temp=heads[i];
	  		while(temp!=NULL)
	  		{
	  			if(temp->data==a)
	  			return temp->rep;
	  			temp=temp->next;
		    }
		}
		  return NULL;
	  }
	  void unoinSet(int a,int b)
	   {
	  	int i,pos,flag=0,j;
	  	struct node *tail2=(struct node*)malloc(sizeof(struct node));
	  	struct node *rep1=find(a);
	  	struct node *rep2=find(b);
	  	if(rep1==NULL||rep2==NULL)
	  	{
	  		printf("Element not present in the datastructure\n");
	  		return;
		  }
		  if(rep1!=rep2)
		  {
		  	for(j=0;j<countRoot;j++)
		  	{
		  		if(heads[j]==rep2)

                 {
                 	pos=j;
                 	flag=1;
					 countRoot=1;
					 tail2=tails[j];
					 for(i=pos;i<countRoot;i++)
					 {
					 	heads[i]=heads[i+1];
					 	
					  }
				}
				if(flag==1)
				break;
			}
				for(j=0;j<countRoot;j++)
				{
					if(heads[j]==rep1)
					{
						tails[j]->next=rep2;
						tails[j]=tail2;
						break;
					}
				} 
				 while(rep2!=NULL)
				 {
				 	rep1->rep=rep1; 
					rep2=rep2->next;		
			
				 }
			}
		}
		int main()
		{
			int  choice,x,i,j,y,flag=0;
			printf("Menu \n1.Make set\n2.Display set representative\n3.Union\n4.Find set\n5.Exit\n");
			do
			{
				printf("Enter your choice");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						printf("Enter new element");
						scanf("%d",&x);
						for(i=0;i<countRoot;i++)
						{
							flag=0;
							if(heads[i]->data==x)
							{
								printf("Element already present in the disjoint set DS\n");
								flag=1;
								break;
								
							}
						}
						if(flag==0)
						makeSet(x);
						break;
					case 2:
					    for(i=0;i<countRoot;i++)
						printf("%d",heads[i]->data);
						printf("\n");
						break;
					case 3:
					    printf("Enter first element");
						scanf("%d",&x);
						printf("Enter second element");
						scanf("%d",&y);
						unoinSet(x,y);
						break;
					case 4:
					    printf("Enter the element");
						scanf("%d",&x);
						struct node *rep=(struct node*)malloc(sizeof(struct node));	
						rep=find(x);
						if(rep==NULL)
						printf("Element not present in DS\n");
						else
						printf("The representative of %d is %d\n",x,rep->data);
						break;
					case 5:
						exit(0);
					default:
						printf("Wrong choice\n");
						
							
							
				}
			}
			while(1);
};
