#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int V[50];
struct edge
{
int u;
int v;
int weight;
}edges[100],MST[100];
struct node
{
   struct node *rep;
   struct node *next;
   int data;
}*heads[50],*tails[50];

static int countRoot=0;
void printMST(int x)
{
int i;
printf("Edges in MST are:\n");
for(i=0;i<x;i++)
printf("%d->%d\n",MST[i].u,MST[i].v);
}
void makeSet(int x)
{
struct node *new=(struct node *)malloc(sizeof(struct node));
new->rep=new;
new->next=NULL;
new->data=x;
heads[countRoot]=new;
tails[countRoot++]=new;
}

struct node* find(int a)
{
int i;
struct node *tmp=(struct node *)malloc(sizeof(struct node));
for(i=0;i<countRoot;i++)
{
tmp=heads[i];
while(tmp!=NULL)
{
if(tmp->data==a)
return tmp->rep;
tmp=tmp->next;
}
}
return NULL;
}

void unionSets(int a,int b)
{
int i,pos,flag=0,j;
struct node *tail2=(struct node *)malloc(sizeof(struct node));
struct node *rep1=find(a);
struct node *rep2=find(b);
if(rep1==NULL||rep2==NULL)
{printf("Vertex not present\n");
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
	countRoot-=1;
	tail2=tails[j];
	for(i=pos;i<countRoot;i++)      //deleting rep2 from the heads
	{
	heads[i]=heads[i+1];

	tails[i]=tails[i+1];
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
rep2->rep=rep1;
rep2=rep2->next;
}
}
}

void main()
{
int i,j,k=1,u,v,m,n,w;
printf("Enter the number of vertices");
scanf("%d",&n);
printf("Enter the vertices");
for(i=0;i<n;i++)
{
scanf("%d",&V[i]);

}


for(i=0;i<n;i++)
makeSet(V[i]);
printf("Enter the number of edges");
scanf("%d",&m);
while(k<=m)
{
printf("Enter the edge %d",k);
scanf("%d%d",&u,&v);
printf("Enter the edge weight ");
scanf("%d",&w);
struct edge new;
new.u=u;
new.v=v;
new.weight=w;
edges[k-1]=new;
k++;
}
//sorting edges list
for(i=0;i<m;i++)
for(j=0;j<m-1;j++)
{
if(edges[j].weight>edges[j+1].weight)
{struct edge tmp;
tmp=edges[j];
edges[j]=edges[j+1];
edges[j+1]=tmp;
}
}


k=0;
for(i=0;i<m;i++)
{struct edge tmp;
tmp=edges[i];
if(find(tmp.u)!=find(tmp.v))
{
MST[k]=tmp;
unionSets(tmp.u,tmp.v);
k++;
}
}
printMST(k);
};55kmm


