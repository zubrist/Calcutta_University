/**
 * Implement an undirected, weighted graph using incidence matrix.
 *
 * Written by Sudipto Ghosh for the University of Calcutta
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

struct Graph
{
  int n, m, edge_num;
  int matrix[MAX_DIM][MAX_DIM];
};

struct Graph *initGraph(int _n, int _m)
{
  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->edge_num = 0;
  graph->n = _n, graph->m = _m;

  for (int i = 0; i < graph->n; i++)
  {
    for (int j = 0; j < graph->m; j++)
    {
      graph->matrix[i][j] = 0;
    }
  }

  return graph;
}

void addEdge(struct Graph *graph, int u, int v, int w)
{
  graph->matrix[u][graph->edge_num] = w;
  graph->matrix[v][graph->edge_num] = w;
  graph->edge_num++;
}

void printGraph(struct Graph *graph)
{
  for (int i = 0; i < graph->n; i++)
  {
    for (int j = 0; j < graph->m; j++)
    {
      printf("%i ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(5, 8);
  addEdge(graph, 0, 1, 2);
  addEdge(graph, 0, 4, 1);
  addEdge(graph, 1, 2, 1);
  addEdge(graph, 1, 3, 3);
  addEdge(graph, 1, 4, 1);
  addEdge(graph, 2, 3, 1);
  addEdge(graph, 3, 0, 1);
  addEdge(graph, 3, 4, 4);
  printGraph(graph);
  free(graph);
  return 0;
}
