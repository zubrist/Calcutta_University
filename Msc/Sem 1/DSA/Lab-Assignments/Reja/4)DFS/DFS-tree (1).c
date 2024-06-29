#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DFSNO 0
#define DFSCOMPNO 1

typedef struct node {
    int vert;
    struct node *adj;
    bool Tree;
}Node;

int dfsno;
int dfscompno;

Node *getnode(int data) {
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->vert = data;
    p->adj = NULL;
    p->Tree = false;
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

void Edges(Node *head[], int size, int **nodeInfo) {
    Node *temp;
    printf("\n\n  Edge       Type\n---------------------------\n");
    for(int i = 0 ; i < size ; i++) {
        temp = head[i];
        while(temp != NULL) {
            if(temp->Tree == true) printf("{%d -> %d} : Tree Edge\n",i,temp->vert);
            else if(temp->Tree != true && nodeInfo[i][DFSNO] < nodeInfo[temp->vert][DFSNO] && nodeInfo[i][DFSCOMPNO] > nodeInfo[temp->vert][DFSCOMPNO])
                printf("{%d -> %d} : Forward Edge\n",i,temp->vert);
            else if(temp->Tree != true && nodeInfo[i][DFSNO] > nodeInfo[temp->vert][DFSNO] && nodeInfo[i][DFSCOMPNO] < nodeInfo[temp->vert][DFSCOMPNO])
                printf("{%d -> %d} : Back Edge\n",i,temp->vert);
            else if(temp->Tree != true && nodeInfo[i][DFSNO] > nodeInfo[temp->vert][DFSNO] && nodeInfo[i][DFSCOMPNO] > nodeInfo[temp->vert][DFSCOMPNO])
                printf("{%d -> %d} : Cross Edge\n",i,temp->vert);
            temp = temp->adj;
        }
    }
}

void DFS(Node *G[], int root, int n, bool *visited, int **nodeInfo) {
    visited[root] = true;
    nodeInfo[root][DFSNO] = dfsno++;
    printf(" %d ",root);
    Node *temp;

    temp = G[root];
    if (temp !=NULL) {
        while (temp != NULL) {
            if(!visited[temp->vert]) {
                temp->Tree = true;
                DFS(G, temp->vert, n, visited, nodeInfo);
            }
            temp = temp ->adj;
            if (temp == NULL) nodeInfo[root][DFSCOMPNO] = dfscompno++;
        }
    }
    else nodeInfo[root][DFSCOMPNO] = dfscompno++;
}

void EdgeClassification(Node *G[], int n, bool *visited, int **nodeInfo) {
    Node *temp;
    for (int i = 0 ; i<n ; i++) {
        temp = G[i];
        while(temp!=NULL) {
            if (temp->Tree == true) temp->Tree = false;
            temp = temp->adj;
        }
        visited[i] = false;
        nodeInfo[i][DFSNO] = 0;
        nodeInfo[i][DFSCOMPNO] = 0;
    }
    int root;
    printf("Enter a root node to start : ");
    scanf("%d", &root);

    if(root >= 0 && root < n) {
        printf("\nDFS traversal from vertex %d : ",root);
        DFS(G,root, n, visited, nodeInfo);
        printf("\n\nNode: [DFS,DFSC] \n----------------\n");
        for(int i=0; i<n; i++) printf(" %d  :  [%d, %d]\n",i,nodeInfo[i][DFSNO], nodeInfo[i][DFSCOMPNO]);
        Edges(G, n, nodeInfo);
    }

    else printf("\nInvalid root!\n");
}

void Components(Node *G[], int n, bool *visited, int **nodeInfo) {
    int Com = 1;
    char c;
    for (int root = 0 ; root<n ; root++) {
        if(!visited[root]) {
            dfsno = 1; dfscompno = 1;
            printf("\nComponent %d : ", Com);
            DFS(G,root,n,visited, nodeInfo); Com++;
            printf("\n");
        }
    }
    do {
        dfsno = 1; dfscompno = 1;
        EdgeClassification(G,n,visited,nodeInfo);
        printf("\n Want to check for another root (y/n) : ");
        scanf(" %c",&c);
    }while(c=='Y' || c=='y');
}

int main() {

    int n; char c;
    printf("Enter number of vertices : ");
    scanf("%d",&n);

    bool *visited = malloc(n * sizeof(bool));

    Node *Graph[n];

    int **nodeInfo = (int **)malloc(n * sizeof(int *));

    for (int i = 0 ; i<n ; i++) {
        Graph[i] = NULL;
        nodeInfo[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Is the Graph directed ? (y/n) : "); scanf(" %c",&c);
    if(c == 'Y' || c=='y') input(Graph, n, 1);
    else input(Graph, n, 0);

    display(Graph, n);
    printf("\n------DFS traversal------\n");

    Components(Graph, n, visited, nodeInfo);

    return 0;
}
