#include<stdio.h>
int main()
{
	int a[10],b[10],m,i,j,n,t;
	printf("Enter the size of first array elements:");
	scanf("%d",&m);
	printf("Enter elements:\n");
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
		printf("Enter the size of second array elements:");
	scanf("%d",&n);
	printf("Enter elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&b[i]);
	for(i=0;i<n;i++)
	a[m+i]=b[i];
	printf("\nElements after merging:\n");
	for(i=0;i<m+n;i++)
	printf("%d\t",a[i]);
	for(i=0;i<m+n;i++)
	{
		for(j=i+1;j<m+n;j++)
		{
		
	     	if(a[i]>a[j])
		   {
			t=a[i];
			a[i]=a[j];
			a[j]=t;
	       }
	    }
	}
	printf("\nElements after sorting\n");
	for(i=0;i<m+n;i++)
	printf("%d\t",a[i]);	
	return 0;
}
