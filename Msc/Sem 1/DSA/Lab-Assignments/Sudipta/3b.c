/**
 * Implement an undirected, weighted graph using adjacency lists.
 *
 * Written by Sudipto Ghosh for the University of Calcutta
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

struct Node
{
  int v, w;
  struct Node *next;
};

struct Graph
{
  int n;
  struct Node *lists[MAX_DIM];
};

struct Graph *initGraph(int _n)
{
  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->n = _n;

  for (int i = 0; i < graph->n; i++)
  {
    graph->lists[i] = malloc(sizeof(struct Node));
    graph->lists[i]->v = 0;
    graph->lists[i]->w = 1;
    graph->lists[i]->next = NULL;
  }

  return graph;
}

void addEdge(struct Graph *graph, int u, int v, int w)
{
  struct Node *node = malloc(sizeof(struct Node));
  node->v = v, node->w = w;
  node->next = graph->lists[u]->next;
  graph->lists[u]->next = node;

  node = malloc(sizeof(struct Node));
  node->v = u, node->w = w;
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
      printf("%i(%i) ", node->v, node->w);
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
  free(graph);
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(5);
  addEdge(graph, 0, 1, 2);
  addEdge(graph, 0, 4, 1);
  addEdge(graph, 1, 2, 1);
  addEdge(graph, 1, 3, 3);
  addEdge(graph, 1, 4, 1);
  addEdge(graph, 2, 3, 1);
  addEdge(graph, 3, 0, 1);
  addEdge(graph, 3, 4, 4);
  printGraph(graph);
  destroyGraph(graph);
  return 0;
}
