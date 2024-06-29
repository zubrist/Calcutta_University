#include<stdio.h>

void dfs(int,int);
void push(int);
int pop();

int adj[20][20],visited[20],solution[20],n, e, d, top=-1,stack[20];

int main()
{
	int i,count=0,j,m;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	printf("\n Enter the number of edges:");
	scanf("%d",&e);
	printf("\n Is the graph directed (1) or undirected (0) ?");
	scanf(" %d",&d);
	for(j=1;j<=e;j++)//Loop for constructing the adjacency matrix
	{ 
		printf("\n Enter the vertices connected by edge %d :",j);	
		scanf("%d,%d",&i,&m);
			adj[i][m]=1;	
			if(d==0)
				adj[m][i]=adj[i][m];
	}
	printf("\n The adjacency matrix representation of the graph is:\n");
	for(i=1;i<=n;i++)
		printf("\tV%d",i);
	for(i=1;i<=n;i++)
	{
		printf("\n");
		printf("V%d",i);
		for(j=1;j<=n;j++)
		{
			printf("\t%d",adj[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)//Checking the visited status of vertex-i
		{
			push(i);
			visited[i]=1;
			dfs(0,i);//Calling the dfs() method using vertex-i
			count++;//Counting components of the graph
		}
	}
	printf("\n No of components = %d",count);
	return 0;
	
}



void dfs(int len,int start)
{
	int p,j,k;
	p=pop();
	solution[len++]=p;
	for(j=1;j<=n;j++)
	{
		if(adj[p][j]==1 && visited[j]==0)//Checking if unvisited vertex J is adjacent to vertex P
		{
			push(j);
			visited[j]=1;
		}
	}
	if(top==-1)//Checking whether the stack is empty
	{
		printf("\n DFS Tree:");
		for(k=0;k<len;k++)
			printf("\t%d",solution[k]);
	}
	else
	{
		dfs(len,stack[top]);//Call the dfs() method using current top-most element of the stack
	}
	
	
}
void push(int item)
{
	top++;
	stack[top]=item;
}
int pop()
{
	int i;
	i=stack[top];
	top--;
	return i;
}


