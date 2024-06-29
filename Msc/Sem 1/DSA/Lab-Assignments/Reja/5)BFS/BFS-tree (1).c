#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int vert;
    struct node *adj;
}Node;

Node *getnode(int data) {
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->vert = data;
    p->adj = NULL;
    return p;
}

void addEdge(Node *head[], int src, int dest) {
    Node *p, *q;
    p = getnode(dest);
    if(head[src] == NULL) head[src] = p;
    else {
        q = head[src];
        if (q -> vert == dest) {
            printf("Vertex Already connected !\n");
            return;
        }
        else {
            while(q->adj != NULL) {
                if(q -> vert == dest) return;
                q = q -> adj;
            }
            q -> adj = p;
        }
    }
}

void input(Node *G[], int size, int directed){

    int s,d; char c;
    do {
        printf("Enter source and destination : ");
        scanf("%d %d",&s,&d);

        if(s >= size || s < 0 || d >= size || d < 0 || s==d) printf("Invalid Input !\n");
        else {
            addEdge(G, s, d);
            if (!directed) addEdge(G, d, s);
        }
        printf("\nDo you want to add edge (y/n) : ");
        scanf(" %c",&c);
    }while(c == 'Y' || c == 'y');
}

void display(Node *head[], int size) {
    Node *temp;
    printf("\n--------------Graph is---------------\n\n");
    for(int i = 0 ; i < size ; i++) {
        temp = head[i];
        printf("%d -> ",i);
        while(temp != NULL) {
            printf("%d -> ", temp->vert);
            temp = temp->adj;
        }
        printf("END\n|\n");
    }
    printf("END\n");
    printf("\n-------------------------------------\n");
}

void flush(bool *visited, int *parent, int n, int *dist) {
    for(int i=0; i<n; i++) {
        visited[i] = false;
        parent[i] = -1;
    }
    *dist = 0;
}

void BFS(Node *G[], int root, int n, bool *visited, int *parent) {
    int queue[n], front=0, rear=0;
    visited[root] = true;
    queue[rear] = root; rear = (rear+1)%n;
    Node *temp;

    while(front != rear) {
        root = queue[front]; front = (front+1)%n;
        printf(" %d ", root);

        temp = G[root];
        while(temp != NULL) {
            if(!visited[temp->vert]) {
                visited[temp->vert] = true;
                parent[temp->vert] = root;
                queue[rear] = temp->vert; rear = (rear+1)%n;
            }
            temp = temp->adj;
        }
    }
}

void Distance(Node *G[], int n, bool *visited) {
    int *parent = malloc(n * sizeof(int));
    int root, dest, temp, distance;
    char c;
    do {
        flush(visited,parent,n,&distance);
        printf("\nEnter source and destination : "); scanf("%d %d", &root, &dest);
        printf("BFS traversal from vertex %d : ",root); BFS(G,root,n,visited,parent);

        if (visited[dest]==false) printf("\nThere is no path between source and destination.\n");
        else if (root == dest) printf("\nInvalid input. Source and destination cannot be same\n");
        else {
            temp=dest;
            printf("\nShortest Path : %d <--",dest);
            while(parent[temp]!=root){
                distance++;
                printf(" %d <--",parent[temp]);
                temp = parent[temp];
            }
            distance++;
            printf(" %d",root);
            printf("\nDistance : %d", distance);
        }
        printf("\nWant to measure distance for another pair (y/n): "); scanf(" %c",&c);

    }while(c=='Y' || c=='y');
}

int main() {

    int n; char c;

    printf("Enter number of vertices : ");
    scanf("%d",&n);

    bool *visited = malloc(n * sizeof(bool));

    Node *Graph[n];
    for (int i = 0 ; i<n ; i++) Graph[i] = NULL;

    printf("Is the Graph directed ? (y/n) : "); scanf(" %c",&c);
    if(c == 'Y' || c=='y') input(Graph, n, 1);
    else input(Graph, n, 0);

    display(Graph, n);
    printf("\n------BFS traversal------\n");

    Distance(Graph, n, visited);

    return 0;
}
