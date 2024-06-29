#include<stdio.h>
#include<stdlib.h>

//Declaring the Global variable visited_matrix & adjecency_matrix
int n, i, j, visited[10], queue[10], front = -1, rear = -1;
int adj[10][10],dist[10],pred[10];

//Function to create the adjecency matrix of undirected graph with arguments
//no. of edge and no. of vertices
void Adj_matrix_udg(int E,int V,int choice){
	int i,j,v1,v2;
	
	//Initializing the entire adjecency matrix with -1
    for(i=0;i<V;i++){
        for(j=0;j<V;j++)
            adj[i][j]=-1;
    }
    
    //Creating the adjecency matrix for undirected Graph
    if(choice==1){
    	for(i=0;i<E;i++){
	    	printf("Enter the edges (format: V1 V2) : ");
	    	scanf("%d%d",&v1,&v2);
	    	adj[v1][v2]=v2;			//Setting destination for source connectivity
	    	adj[v2][v1]=v1;			//Setting source for destination connectivity
		}	
	}
	else if(choice==2){
		for(i=0;i<E;i++){
	    	printf("Enter the edges (format: V1 V2) : ");
	    	scanf("%d%d",&v1,&v2);
	    	adj[v1][v2]=v2;			//Setting destination for source connectivity
		}
	}
	else{
		printf("WRONG CHOICE...!!!!\nGraph must be directed or undirected\n");
		exit(0);
	}
	
	
	//Displaying the adjecency matrix 
	printf("\nAdjacency Matrix\n");
	for(i=0;i<V;i++){
	    for(j=0;j<V;j++){
	    	printf(" %d ",adj[i][j]);	
		}
	    printf("\n");
	}
	printf("\n -1 denotes there is no connection between vertices\n\n");
}

int bfs(int v,int src){
	int i,u;
	
	visited[src]=1;			//Marking the source vertex as 1
	dist[src]=0;
	rear++;
	queue[rear]=src;
	front++;
	printf("\nThe BFS traversal is : \n");
	while(front <= rear){			//While queue not empty
		u=queue[front];
		printf("%d ",queue[front]);			//removing the front element and displaying it
		front++;
		for(i=0 ; i<v ; i++){
			if(adj[u][i] != -1 && visited[adj[u][i]] == 0){
				visited[adj[u][i]] = 1;			// Marking the visited vertex with 1
				rear++;
                queue[rear]=adj[u][i];		//inserting the new vertex into queue
			}
		}
	}
}

int short_dist(int v,int src,int dest){
	int i,u,flag = 0;
	rear=-1,front=-1;
	//initializing the pedecesor as -1 and 
	//distance between vetex with infinity
	for(i=0;i<v;i++){
		pred[i]=-1;
		dist[i]=99999;
		queue[i] = 0;
        visited[i] = 0;
	}
	
	visited[src]=1;			//Marking the source vertex as 1
	dist[src]=0;
	rear++;
	queue[rear]=src;
	front++;
	printf("\nThe BFS traversal for %d as source is : \n",src);
	while(front <= rear){			//While queue not empty
		u=queue[front];
		printf("%d ",queue[front]);			//removing the front element and displaying it
		front++;
		for(i=0 ; i<v ; i++){
			if(adj[u][i] != -1 && visited[adj[u][i]] == 0){
				visited[adj[u][i]] = 1;			// Marking the visited vertex with 1
				rear++;
                queue[rear]=adj[u][i];		//inserting the new vertex into queue
                //Calculating the distance and predecessor
	            if (flag == 0){
	                dist[adj[u][i]] = dist[u] + 1;
	                pred[adj[u][i]] = u;
				} 
					
				//Checking if the destination is reached and setting the flag 1
		        if (adj[u][i] == dest){
		            flag = 1;
				}  

			}
		}
	}
	return flag;
}

void print_distance(int src,int dest,int v){
	int path[10],crawl,k=0;
	for(i=0;i<v;i++){
		pred[i]=0;
		dist[i]=0;
	}
	
	//Checking if the source and destination is connected or not
	if(short_dist(v,src,dest) == 0){
		printf("Given source and destination are not connected");
	}
	

	crawl=dest;
	path[k]=crawl;
	
	while(pred[crawl] != -1){
		path[++k] = pred[crawl];
		crawl = pred[crawl];
	}
	
	printf("\nThe shortest distance from vertex %d to vertex %d is %d",src,dest,dist[dest]);
	printf("\nPath is ::\n");
	
	//Displaying the shortest path
	for(i=k;i>=0;i--){
		printf("%d  ",path[i]);
	}
}

int main()
{
    int v,e,s,d,ch;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < v; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    
	printf("\n\tMENU\nPress 1 for undirected Graph.\nPress 2 for directed Graph.\n");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);

    Adj_matrix_udg(e,v,ch);
    printf("\nEnter the source ");
    scanf("%d",&s);
   	bfs(v,s);
    printf("\nEnter the source and destination vertex: ");
    scanf("%d%d",&s,&d);
    print_distance(s,d,v);
    
    return 0;
}