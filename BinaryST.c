#include<stdio.h>
#include<stdlib.h>
struct node
   {
	     int data;
	     struct node *right;
	     struct node *left;
   }*root;
	    int n,i=0;
     	struct node* search(struct node *root,int x)
	   {
		   if(root==NULL||root->data==x)
	     	return root;
	      else if(root->data<x)
	    	return search(root->right,x);
	    	else
	    	return search(root->left,x);
    	}
	  struct node *new_node(int x)
     	{
        	struct node *p;
        	p=(struct node*)malloc(sizeof(struct node));
        	if(p==NULL)
	        {
	       	printf("Unable to allocate memory");
	    	exit(0);
	    	}
	    }
	     	struct node* insert(struct node *root,int x)
	    	{
		     	if(root==NULL)
		     	return new_node(x);
		    	else if(root->data>x)
		    	root->left=insert(root->left,x);
		    	else
		    	root->right=insert(root->right,x);
		    	return root;
			}
			struct node *find_minimum(struct node *root)
		    	{
		        	if(root==NULL)
		    	    return NULL;
			        if(root->left==NULL)
		        	return root;
		        	return find_minimum(root->left);	
			 	}
			struct node* delete(struct node *root,int x)
				{
				  if(root==NULL)
			    	return NULL;
			    	if(root->data>x)
			    	root->left=delete(root->left,x);
			     	else if(root->data<x)
			    	root->right=delete(root->right,x);
			    	else
			    	{
					     if(root->left==NULL&&root->right==NULL)//nochild
					
				     	{
						free(root);
						return NULL;
				    	}
					
				    	else if(root->left==NULL||root->right==NULL)//one child
					   {
						struct node *temp;
						if(root->left==NULL)
						temp=root->right;
						if(root->right==NULL)
						temp=root->left;
						free(root);
						return temp;
					   }
				    	else//2 children
				     	{
						struct node *temp;
						temp=find_minimum(root->right);
						root->data=temp->data;
						root->right=delete(root->right,temp->data);
						
					   }
				}
			
			
				return root;
    	}
				int main()
				{
				   int choice ,x;
				    printf("BST\nEnter the maximum element that the BST can have");
			     	scanf("%d",&n);
				    printf("Menu\n1.Insert\n2.Delete\n3.Search\n4.Exit\n");
			    	do
				   {
			        	printf("Enter your choice");
				        scanf("%d",&choice);
			        	switch(choice)
			        	{
				  	case 1:
						if(i==n)
						printf("No more insertion possible.Number of tree nodes has reached the limit");
						else
						{
							printf("Enter the data to be inserted");
							scanf("%d",&x);
							if(root==NULL)
							root=new_node(x);
							else
							insert(root,x);
							i++;
						}
						break;
					case 2:
					if(root==NULL)
					printf("The BST is empty\n");
					else
					   {  
						printf("Enter data to be deleted");
						scanf("%d",&x);
						root=delete(root,x);
						i--;
						}	
					break;
					case 3:
						printf("Enter data to be searched");
						scanf("%d",&x);
						if(search(root,x)==NULL)
						printf("Not found");
						else
						printf("Found");
						break;
						case 4:
							exit(0);
						default:
						printf("Wrong choice\n");
						break;
							
						
					}	
				}
					while(1);
					return 0;	
				
			};
		
					
	

