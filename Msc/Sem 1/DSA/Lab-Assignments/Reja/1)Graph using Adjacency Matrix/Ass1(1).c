#include<stdio.h>
void input(int);
void adjacency(int,int);

int adj[20][20],v[20][2],cost[20],n,e;
void main()
{
	int i,j,m,f,ch;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	printf("\n Enter the number of edges:");
	scanf("%d",&e);
	do
	{
		printf("\n Select a value according to the graph, you want to input:\n");
		printf("\n 1-Undirectional & Unweighted\n");
		printf("\n 2-Undirectional & Weighted \n");
		printf("\n 3-Directional & Unweighted \n");
		printf("\n 4-Directional & Weighted \n");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: adjacency(0,0);
					break;
			case 2: adjacency(0,1);
					break;
			case 3: adjacency(1,0);
					break;
			case 4: adjacency(1,1);
					break;						
			default: printf("\n You have entered wrong choice!!");
			
		}
		printf("\n Do you wish to continue? Press 1 for YES, 0 for NO: ");
		scanf("%d",&f);
		if(f==1)
		{
				
				printf("\n Please re-enter the number of vertices:");
				scanf("%d",&n);
				printf("\n Pleae re-enter the number of edges:");
				scanf("%d",&e);
		}
		
	}while(f==1);
	printf("\n Thank You for using the program!!!");
		
}

void adjacency(int d, int w)
{
	int m,i,j;
	
	
	printf("\n NOTE: Please use comma (,) as the separator between the input vertices.");
	for(i=1;i<=e;i++)
	{ 
		printf("\n Enter the vertices connected by edge %d :",i);	
		scanf("%d,%d",&v[i][0],&v[i][1]);
		if(w==1)//For weighted graph
		{
			printf("\n Please enter the cost of the edge:");
			scanf("%d",&cost[i]);
		}
	}
	
	//Finding the adjacency matrix
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=e;j++)
		{
			if(i==v[j][0] )	//Checking if vertex-i is the end vertex of edge-j
			{
				m=v[j][1];//Storing the other end vertex of edge-j	
				if(w==1)//For weighted graph
					adj[i][m]=cost[j];
				else if (w==0)//For unweighted graph
					adj[i][m]=1;	
				if(d==0)//For undirectional graph
					adj[m][i]=adj[i][m];
			}
		}
	}
	printf("\n The adjacency matrix is:\n");
	for(i=1;i<=n;i++)
		printf("\tV%d",i);
	for(i=1;i<=n;i++)
	{
		printf("\n");
		printf("V%d",i);
		for(j=1;j<=n;j++)
		{
			if(w==1)
			{
				if(adj[i][j]==0 && i!=j)
					printf("\tINF");
				else if(adj[i][j]==0 && i==j)
					printf("\t---");	
				else
					printf("\t%d",adj[i][j]);	
			}
			else
				printf("\t%d",adj[i][j]);
		}
		printf("\n");
	}
	if(w==1)
	printf("\n NOTE: INF indicates infinity\n --- indicates Not Applicable. ");
	
}
		
