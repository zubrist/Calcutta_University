
//Graph Sort
#include<stdio.h>

int  source[200],adj[200][200],v[200], sorted[200],n;
int find_source();
void modify_graph(int);
void display();
void main()
{
	int i,j,m1;
	printf("\n Enter the number of elements:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n Enter the element at position-%d::",i);
		scanf("%d",&v[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(v[j]>v[i])
			{
				
				adj[i][j]=1;//adjacency matrix creation
				
			}
			else
				adj[i][j]=0;
				
		}
	}

	printf("\n The set of vertices:");
	for(i=1;i<=n;i++)
	{
		printf("\n positional value %d assigned to element %d", i,v[i]);//assign positional value
		
	}
	printf("\n The adjacency matrix representation of the oriented RKPian Graph is:\n");
	display();
	for(i=1;i<=n;i++)
	{
		printf("\n Iteration-%d",i);
		m1=find_source();
		sorted[i]=v[m1];
		printf("\n Deleting the vertex-%d (associated with value: %d )\n",m1,v[m1]);
		modify_graph(m1);
		//display();
	}
	printf("\n Hence, the sorted list is as follows:\n");
	for(i=1;i<=n;i++)
		printf("\n %d",sorted[i]);
	
	
}

int find_source()
{
	int f,c,i,j,min,m,p,q,k,g;
	f=0;
	c=1;
	for(j=1;j<=n;j++)
	{
		f=0;
		for(i=1;i<=n;i++)
		{
			if(adj[i][j]!=0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			source[c++]=j;
		}
		
	}
	printf("\n The positional values of source vertices are:");
	
	for(i=1;i<c;i++)
	{
		printf("\n V-%d ",source[i]);//positional values of source vertices aren printed
	}
	return source[c-1];
	
	
}
void modify_graph(int d)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		adj[d][i]=0;
		adj[i][d]=-1;
	}
	
}
void display()
{
	int i,j;

	for(i=1;i<=n;i++)
		printf("\tV%d",i);
	for(i=1;i<=n;i++)
	{
		printf("\n");
		printf("V%d",i);
		for(j=1;j<=n;j++)
		{
			if(adj[i][j]==-1)
				printf("\t0");
			else
				printf("\t%d",adj[i][j]);
		}
		printf("\n");
	}
}
