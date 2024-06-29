/**
 * Consider an undirected graph. Do DFS on it and differentiate the edges based
 * on your sequence of visiting the vertices.
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
  int clock;
  int *visited;
  int *start, *end;
  struct Node *lists[MAX_DIM];
};

struct Graph *initGraph(int _n)
{
  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->n = _n;
  graph->clock = 0;
  graph->visited = malloc(sizeof(int) * _n);
  graph->start = malloc(sizeof(int) * _n);
  graph->end = malloc(sizeof(int) * _n);

  for (int i = 0; i < graph->n; i++)
  {
    graph->lists[i] = malloc(sizeof(struct Node));
    graph->lists[i]->v = 0;
    graph->lists[i]->next = NULL;
    graph->visited[i] = 0;
    graph->start[i] = 0;
    graph->end[i] = 0;
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
  free(graph->start);
  free(graph->end);
  free(graph);
}

void resetGraphState(struct Graph *graph)
{
  for (int i = 0; i < graph->n; i++)
  {
    graph->visited[i] = 0;
    graph->start[i] = 0;
    graph->end[i] = 0;
  }

  graph->clock = 0;
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

void DFSEdgeClassification(struct Graph *graph, int u)
{
  graph->visited[u] = 1;
  graph->start[u] = graph->clock;
  struct Node *node = graph->lists[u]->next;
  while (node != NULL)
  {
    if (!graph->visited[node->v])
    {
      printf("Tree Edge: {%i, %i}\n", u, node->v);
      DFSEdgeClassification(graph, node->v);
    }
    else
    {
      if (graph->start[node->v] < graph->start[u] && graph->end[node->v] < graph->end[u])
        printf("Cross Edge: {%i, %i}\n", u, node->v);
      else if (graph->start[node->v] < graph->start[u] && graph->end[node->v] > graph->end[u])
        printf("Back Edge: {%i, %i}\n", u, node->v);
      else if (graph->start[node->v] > graph->start[u] && graph->end[node->v] < graph->end[u])
        printf("Forward Edge: {%i, %i}\n", u, node->v);
    }
    graph->end[u] = ++graph->clock;
    node = node->next;
  }
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(7);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 6);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5);
  addEdge(graph, 4, 6);
  addEdge(graph, 5, 6);
  printf("Graph: \n");
  printGraph(graph);

  struct Graph *tree = initGraph(7);
  DFSTree(graph, 0, tree);
  printf("DFS Tree: \n");
  printGraph(tree);
  resetGraphState(graph);

  printf("Edge Classification: \n");
  DFSEdgeClassification(graph, 0);
  resetGraphState(graph);

  destroyGraph(graph);
  destroyGraph(tree);
  return 0;
}
