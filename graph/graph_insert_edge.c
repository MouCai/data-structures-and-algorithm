#include "graph.h"

int graph_insert_edge(Graph *graph, const void *data1, const void *data2) {
  ListElm *element;
  int result;

  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (graph->match(data2, ((AdjList *)list_data(element))->vertex))
      break;
  }
  if (element == NULL)
    return -1;
  
  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (graph->match(data1, ((AdjList *)list_data(element))->vertex))
      break;
  }
  if (element == NULL)
    return -1;

  if ((result = set_insert(&((AdjList *)list_data(element))->adjacent, data2)) != 0)
    return result;

  graph->ecount++;
  return 0;
}
