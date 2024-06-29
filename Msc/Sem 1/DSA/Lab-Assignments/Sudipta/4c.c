/**
 * Compute the number of components of a given undirected graph using DFS.
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

void DFS(struct Graph *graph, int v)
{
  graph->visited[v] = 1;

  struct Node *node = graph->lists[v]->next;
  while (node != NULL)
  {
    if (graph->visited[node->v] == 0)
    {
      DFS(graph, node->v);
    }
    node = node->next;
  }
}

int connectedComponents(struct Graph *graph)
{
  int count = 0;
  for (int i = 0; i < graph->n; i++)
  {
    if (!graph->visited[i])
    {
      DFS(graph, i);
      count++;
    }
  }
  return count;
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(7);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 0);
  addEdge(graph, 3, 4);
  addEdge(graph, 5, 6);
  printf("Graph: \n");
  printGraph(graph);

  printf("Connected Components: %i\n", connectedComponents(graph));

  destroyGraph(graph);
  return 0;
}
