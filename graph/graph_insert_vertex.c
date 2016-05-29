#include "graph.h"

int graph_insert_vertex(Graph *graph, const void *data) {
  ListElm *element;
  AdjList *adjlist;
  int result;

  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (graph->match(data, ((AdjList *)list_data(element))->vertex)) 
      return 1;
  }

  if ((adjlist = (AdjList *)malloc(sizeof(AdjList))) == NULL)
    return -1;

  adjlist->vertex = (void *)data;
  set_init(&adjlist->adjacent, graph->match, NULL);
  
  if ((result = list_push(&graph->adjlists, adjlist)) != 0)
    return result;

  graph->vcount++;
  return 0;
}
