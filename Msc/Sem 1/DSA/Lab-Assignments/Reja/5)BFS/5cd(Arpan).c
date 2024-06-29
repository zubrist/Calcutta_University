#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int value;
	int parent;
	struct node* next;
}node;
int *visited, *permanent_list, v, e, type, reachable=0, f;
node *adj_list;

int extend_array(int templist[], int val){
	templist[++templist[0]]=val;
}

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

void bfs(int top, int templist[]){
	int i;
	node* x = (adj_list+top);
	while(x!=NULL){
		if(visited[x->value]==0){
			extend_array(templist, x->value);
			if(x->value == f){
				if(templist[0]<permanent_list[0])
				for(i=0;i<templist[0]+1;i++){
					permanent_list[i]=templist[i];
				}
				visited[x->value]=1;
				continue;
			}
			visited[x->value]=1;
			bfs(x->value, templist);
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
	permanent_list = (int*)calloc(v+1, sizeof(int));

	int templist[v+1];
	templist[0]=0;
	*permanent_list = v;

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
	printf("Enter the starting and finding node: ");
	scanf("%d%d", &c, &f);
	bfs(c, templist);

	for(i=1;i<permanent_list[0]+1;i++){
		printf("%d ", permanent_list[i]);
	}
}