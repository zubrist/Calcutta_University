#include<stdio.h>
#include<stdlib.h>

typedef struct node{ //Structure to define a node/vertex
    int index; //Data value
    int weight; //Weight value
    struct node *next; //Pointer
}node;

int n; //Number of vertices
node** adjlist; //Adjacency list of pointers to structures

node* create_node(int i, int w){
    node *p;
    p=(node*)malloc(sizeof(node));
    p->index=i;
    p->weight=w;
    p->next=NULL;
    return p;
}

void create_graph(){
    int i;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Therefore the vertices are: ");
		for(i=0;i<n;i++) { //Displaying name of nodes
			printf("%d ",i);
	}
    //Initializing the adjacency list
    adjlist=(node**)malloc(n*sizeof(node*));
    for(i=0;i<n;i++){
        adjlist[i]=NULL;
    }
}

void enter_edges(){
    int v1,v2,w,ne;
    node *s,*d;
    ne=1;
    do{
    	printf("\nEnter edge %d. Enter -999 to stop.\n",ne);
        printf("Enter source: ");
        scanf("%d",&v1);
        printf("Enter destination: ");
        scanf("%d",&v2);
		printf("Enter weight: ");
        scanf("%d",&w);
        if(v1>=0 && v1<n && v2>=0 && v2<n){
            //Making an entry of the destination in the source list
            d=create_node(v2,w);
            d->next=adjlist[v1];
            adjlist[v1]=d;
            //Making an entry of the source in the destination list
            s=create_node(v1,w);
            s->next=adjlist[v2];
            adjlist[v2]=s;
        }
        else if(v1!=-999 && v2!=-999){
            printf("\nError: Enter a valid edge.\n");
            continue;
        }
        ne++;
    }while(v1!=-999 && v2!=-999);
}

void display(){
    int i;
    int flag = 0;
    node *p,*q;
    printf("\nAdjacency List:\n");
    for(i=0;i<n;i++){
        printf("Node %d",i);
        p=adjlist[i];
        q=NULL;
        while(p!=NULL){
        	flag=1;
            printf("-(%d)->%d",p->weight,p->index);
            p=p->next;
        }
        printf("->X\n");
    }
}

int main() {
	create_graph();
	enter_edges();
	display();	
}
