/**
 * Consider an undirected graph. Do BFS on it and compute the BFS tree.
 *
 * Written by Sudipto Ghosh for the University of Calcutta
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

struct Node
{
  int v;
  struct Node *next;
};

struct Graph
{
  int n;
  int *visited;
  struct Node *lists[MAX_DIM];
};

struct Graph *initGraph(int _n)
{
  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->n = _n;
  graph->visited = malloc(sizeof(int) * _n);

  for (int i = 0; i < graph->n; i++)
  {
    graph->lists[i] = malloc(sizeof(struct Node));
    graph->lists[i]->v = 0;
    graph->lists[i]->next = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

void addEdge(struct Graph *graph, int u, int v)
{
  struct Node *node = malloc(sizeof(struct Node));
  node->v = v;
  node->next = graph->lists[u]->next;
  graph->lists[u]->next = node;

  node = malloc(sizeof(struct Node));
  node->v = u;
  node->next = graph->lists[v]->next;
  graph->lists[v]->next = node;
}

void printGraph(struct Graph *graph)
{
  for (int i = 0; i < graph->n; i++)
  {
    struct Node *node = graph->lists[i]->next;
    printf("%i: ", i);
    while (node != NULL)
    {
      printf("%i ", node->v);
      node = node->next;
    }
    printf("\n");
  }
}

void destroyGraph(struct Graph *graph)
{
  for (int i = 0; i < graph->n; i++)
  {
    struct Node *node = graph->lists[i]->next;
    while (node != NULL)
    {
      struct Node *temp = node;
      node = node->next;
      free(temp);
    }
    free(graph->lists[i]);
  }
  free(graph->visited);
  free(graph);
}

void resetVisited(struct Graph *graph)
{
  for (int i = 0; i < graph->n; i++)
  {
    graph->visited[i] = 0;
  }
}

void BFSTraversal(struct Graph *graph, int u)
{
  int queue[graph->n];
  int front = 0, rear = 0;

  graph->visited[u] = 1;
  queue[rear++] = u;

  while (front != rear)
  {
    int u = queue[front++];
    printf("%i ", u);

    struct Node *node = graph->lists[u]->next;
    while (node != NULL)
    {
      if (!graph->visited[node->v])
      {
        graph->visited[node->v] = 1;
        queue[rear++] = node->v;
      }
      node = node->next;
    }
  }
}

void BFSTree(struct Graph *graph, int u, struct Graph *tree)
{
  int queue[graph->n];
  int front = 0, rear = 0;

  graph->visited[u] = 1;
  queue[rear++] = u;

  while (front != rear)
  {
    int u = queue[front++];

    struct Node *node = graph->lists[u]->next;
    while (node != NULL)
    {
      if (!graph->visited[node->v])
      {
        addEdge(tree, u, node->v);
        graph->visited[node->v] = 1;
        queue[rear++] = node->v;
      }
      node = node->next;
    }
  }
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 0);
  addEdge(graph, 3, 4);
  printf("Graph: \n");
  printGraph(graph);

  printf("BFS Traversal: ");
  BFSTraversal(graph, 0);
  resetVisited(graph);

  struct Graph *tree = initGraph(5);
  BFSTree(graph, 0, tree);
  printf("\nBFS Tree: \n");
  printGraph(tree);
  resetVisited(graph);

  destroyGraph(graph);
  destroyGraph(tree);
  return 0;
}
