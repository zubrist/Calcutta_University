/**
 * Consider an undirected graph. Do BFS on it and compute the shortest path between
 * two nodes, if it exists
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

void BFSShortestPath(struct Graph *graph, int u, int v)
{
  int *path = malloc(sizeof(int) * graph->n);
  int *distance = malloc(sizeof(int) * graph->n);
  int *queue = malloc(sizeof(int) * graph->n);
  int front = 0, rear = 0;

  queue[rear++] = u;
  graph->visited[u] = 1;
  path[u] = -1;
  distance[u] = 0;

  while (front != rear)
  {
    int node = queue[front++];
    struct Node *temp = graph->lists[node]->next;
    while (temp != NULL)
    {
      if (graph->visited[temp->v] == 0)
      {
        queue[rear++] = temp->v;
        graph->visited[temp->v] = 1;
        path[temp->v] = node;
        distance[temp->v] = distance[node] + 1;
      }
      temp = temp->next;
    }
  }

  free(queue);

  if (distance[v] == 0)
  {
    printf("No Path (%i, %i) Exists\n", u, v);
  }
  else
  {
    printf("Shotest Distance (%i, %i): %i\n", u, v, distance[v]);
    printf("Path (%i <- %i): ", v, u);
    int node = v;
    while (node != -1)
    {
      printf(node == u ? "%i" : "%i <- ", node);
      node = path[node];
    }
    printf("\n");
  }

  free(path);
  free(distance);
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(7);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 6);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 1);
  addEdge(graph, 4, 5);
  addEdge(graph, 6, 4);
  addEdge(graph, 6, 5);
  printf("Graph: \n");
  printGraph(graph);

  BFSShortestPath(graph, 0, 4);
  resetVisited(graph);

  destroyGraph(graph);
  return 0;
}
