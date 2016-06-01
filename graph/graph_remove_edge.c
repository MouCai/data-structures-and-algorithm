#include "graph.h"
int graph_remove_edge(Graph *graph, void *data1, void **data2) {
  ListElm *element, *temp;

  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (graph->match(data1, ((AdjList *)list_data(element))->vertex))
      break;
  }

  if (element == NULL)
    return -1;

  if (set_remove(&((AdjList *)list_data(element))->adjacent, data2) != 0)
    return -1;

  graph->ecount--;
  return 0;
}
