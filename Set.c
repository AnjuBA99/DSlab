#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int A[20],B[20],universal[20],bitstringA[20],bitstringB[20],bitstringU[20],nA,nB,nU;
	void getSet(int x[],int n)
	{
	int i;
	for(i=0;i<n;i++)
	{
	printf("Enter element %d",(i+1));
	scanf("%d",&x[i]);
	}
	}
int search(int x[],int n,int elem)
{int i;
for(i=0;i<n;i++)
{
if(x[i]==elem)
return i;
}
return -1;
}
	void generateBitString(int x[],int n,int bitstring[])
	{
	int i,pos;
	for(i=0;i<nU;i++)
	{
	bitstring[i]=0;
	}
	for(i=0;i<n;i++)
	{
	pos=search(universal,nU,x[i]);
	if(pos!=-1)
	bitstring[pos]=1;
	}
	for(i=0;i<nU;i++)
	printf("%d ",bitstring[i]);
	}

void printSet(int x[],int n)
{
int i;
printf("{");
for(i=0;i<n;i++)
{
if(i==n-1)
printf("%d } \n",x[i]);
else
printf("%d,",x[i]);
}
}
	void printAllSets(){
 	printf("Universal Set:");
 	printSet(universal,nU);
 	printf("Set A:");
 	printSet(A,nA);
 	printf("Set B:");
 	printSet(B,nB);
	}
void toSet(int bitstring[],int n)
{
int i,c=0;
printf("{");
for(i=0;i<nU;i++)
{
if(bitstring[i]==1)
{c++;
if(c==n)
printf("%d } \n",universal[i]);
else
printf("%d,",universal[i]);
}
}
}
	void unionSet(int bitstringX[],int bitstringY[])
	{
	int i,n=0;
	int bitstringUnion[20];
	for(i=0;i<nU;i++)
	{
	bitstringUnion[i]=bitstringX[i] | bitstringY[i];
	n+=bitstringUnion[i];
	}
	toSet(bitstringUnion,n);

	}
void intersectionSet(int bitstringX[],int bitstringY[])
{
int i,n=0;
int bitstringAns[20];
for(i=0;i<nU;i++)
{
bitstringAns[i]=bitstringX[i] & bitstringY[i];
n+=bitstringAns[i];
}
toSet(bitstringAns,n);

}

	void differenceSet(int bitstringX[],int bitstringY[])
	{
	int i,n=0;
	int bitstringAns[20];
	int yComplement[nU];
	for(i=0;i<nU;i++)
	{
	if(bitstringY[i]==1)
	yComplement[i]=0;
	else
	yComplement[i]=1;
	}
	for(i=0;i<nU;i++)
	{
	bitstringAns[i]=bitstringX[i] & yComplement[i];
	n+=bitstringAns[i];
	}
	toSet(bitstringAns,n);
	}
void main()
{
int choice;
	
	printf("Menu\n1.Enter set A\n2.Enter set B\n3.Enter Universal Set\n4.Generate bitString of A\n5.Generate bitString of B\n6.Generate bitString of Universal set\n7.Union\n8.Intersection\n9.Difference\n10.Print all sets\n8.Exit\n");
	do
	{
		printf("Enter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter n ");
			scanf("%d",&nA);
			getSet(A,nA);
			break;
		case 2:
			printf("Enter n ");
			scanf("%d",&nB);
			getSet(B,nB);
			break;
		case 3:
			printf("Enter n ");
			scanf("%d",&nU);
			getSet(universal,nU);
			break;
		case 4:
			generateBitString(A,nA,bitstringA);
			break;
		case 5:
			generateBitString(B,nB,bitstringB);		
			break;
		case 6:
			generateBitString(universal,nU,bitstringU);
			break;
		case 7:
			unionSet(bitstringA,bitstringB);
			break;
		case 8:
			intersectionSet(bitstringA,bitstringB);
			break;
		case 9:
			differenceSet(bitstringA,bitstringB);
			break;
		case 10:
			printAllSets();
			break;
		case 11:
			exit(0);
		default: 
			printf("Wrong choice\n");
			break;
	}
	}
	while(1);
	
}

