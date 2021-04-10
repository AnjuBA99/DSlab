#include<stdio.h>
#include<conio.h>

#define INF 9999999

int V[50],E[50][50],queue[50],n,visited[50],rear=-1,front=-1,key[50],parent[50];
void enqueue(int x)
{
	
	if(front==-1)
	front=0;
	rear++;
	queue[rear]=x;
	
	
}
int dequeue()
{
	int item=queue[front];
visited[item]=1;
		if(front==rear)
		{
		front=-1;
		rear=-1;
		}
		else
		front++;
	return item;

}
void Prims()
{
int u,v,x,y,tmp,i,j;
enqueue(0);

while(front!=-1)
{

 u=dequeue();

 for(i=0;i<n;i++)
 {
 if(E[u][i]!=0)
 {
 v=i;
 if(visited[v]==0)
 {
 enqueue(v);
 if(key[v]>E[u][v])
 {key[v]=E[u][v];
 parent[v]=u;
 }
 
 }
 }
 }
//sorting queue
for(i=front;i<=rear;i++)
for(j=front;j<=rear-1;j++)
{
x=queue[j];
y=queue[j+1];
if(key[x]>key[y])
{
tmp=queue[j];
queue[j]=queue[j+1];
queue[j+1]=tmp;
}
}






}

}
void printMST()
{
int i;
printf("MST obtained through Prims is\n");
for(i=0;i<n;i++)
{
if(parent[i]!=-1)
printf("%d -> %d (Weight:%d)\n",parent[i],V[i],key[i]);
}
}
void main()
{
int i,j,k=1,u,v,m;
printf("Enter the number of vertices");
scanf("%d",&n);
printf("Enter the vertices");

for(i=0;i<n;i++)
{
scanf("%d",&V[i]);
visited[i]=0;
key[i]=INF;
parent[i]=-1;
}
key[0]=0;
printf("Enter the adjacency matrix");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&E[i][j]);
Prims();
printMST();
}
