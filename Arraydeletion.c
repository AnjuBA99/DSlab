#include<stdio.h>
int main()
{
	int arr[10],i,pos,n;
	printf("Enter the size of the array\t");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("Enter the position to be deleted\t");
	scanf("%d",&pos);
	if(pos>0&&pos>n)
	printf("Enter a valid position in between 0 and %d\t",n);
	else
    {
	for(i=pos-1;i<n-1;i++)
	arr[i]=arr[i+1];
	n--;
   }
   printf("Display the elements after deletion are \n");
   for(i=0;i<n;i++)
   printf("%d\t",arr[i]);
   return 0;
  }

