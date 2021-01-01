#include<stdio.h>
int main()
{
	int arr[10],pos,i=0,n,item;
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	printf("Enter the %d elements\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\nEnter the position to which the element to be added\n");
	scanf("%d",&pos);
	if(pos<0||pos>n)
	{
	
	printf("\n ARRAY OVERFLOW\n");
	exit(0);
    }
	printf("\nEnter the value to be added\n");
	scanf("%d",&item);
	for(i=n-1;i>=pos-1;i--)
	arr[i+1]=arr[i];
	arr[pos-1]=item;
	
	printf("\nThe array elements are\n");
	for(i=0;i<=n;i++)
	printf("%d\t",arr[i]);
	return 0;
	}
