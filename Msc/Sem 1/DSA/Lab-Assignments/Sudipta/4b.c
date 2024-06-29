/**
 * Consider a directed graph. Do DFS on it and compute the DFS tree.
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

void DFSTraversal(struct Graph *graph, int v)
{
  graph->visited[v] = 1;
  printf("%i ", v);

  struct Node *node = graph->lists[v]->next;
  while (node != NULL)
  {
    if (graph->visited[node->v] == 0)
    {
      DFSTraversal(graph, node->v);
    }
    node = node->next;
  }
}

void DFSTree(struct Graph *graph, int v, struct Graph *tree)
{
  graph->visited[v] = 1;

  struct Node *node = graph->lists[v]->next;
  while (node != NULL)
  {
    if (!graph->visited[node->v])
    {
      addEdge(tree, v, node->v);
      DFSTree(graph, node->v, tree);
    }

    node = node->next;
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

  printf("DFS Traversal: ");
  DFSTraversal(graph, 0);
  resetVisited(graph);

  struct Graph *tree = initGraph(5);
  DFSTree(graph, 0, tree);
  printf("\nDFS Tree: \n");
  printGraph(tree);
  resetVisited(graph);

  destroyGraph(graph);
  destroyGraph(tree);
  return 0;
}
