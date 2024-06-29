#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	int parent;
	struct node* next;
}node;
int *visited, v, e, type, reachable=0;
node *adj_list;
int addedge(int i, int j, node* adj_list){
	node* x = (adj_list+i);
	while(x->next!=NULL){
		x = x->next;
	}
	x = x->next = (node*)calloc(1, sizeof(node));
	x->value = j;
	x->parent = i;
	x->next = NULL;
}
void bfs(int top){
	node* x = (adj_list+top);
	visited[x->value]=1;
	x = x->next;
	while(x!=NULL){
		if(visited[x->value]==0){
			visited[x->value]=2;
			printf("%d ", x->value);
		}
		x = x->next;
	}
	x = (adj_list+top)->next;
	while(x!=NULL){
		if(visited[x->value]==2){
			visited[x->value]=1;
			bfs(x->value);
		}
		x = x->next;
	}
}
int main(){
	int c, i, j, components=0;
	printf("Enter the type of graph(0/1 for undirected/directed): ");
	scanf("%d", &type);
	printf("Enter the number of vertex and edges: ");
	scanf("%d%d", &v, &e);
	
	visited = (int *)calloc(v, sizeof(int));
	adj_list = (node*)calloc(v, sizeof(node));

	for(i=0;i<v;i++){
		(adj_list+i)->next = NULL;
		(adj_list+i)->parent = -1;
		(adj_list+i)->value = i;
	}
	
	for(i=0;i<e;i++){
		int x, y;
		printf("Enter the edge: ");
		scanf("%d%d", &x, &y);
		addedge(x, y, adj_list);
		if(type==0){
			addedge(y, x, adj_list);
		}
	}
	printf("Enter the starting node: ");
	scanf("%d", &c);
	
	printf("%d ", c);
	bfs(c);
}