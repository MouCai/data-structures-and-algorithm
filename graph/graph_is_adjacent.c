#include "graph.h"

int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2) {
  ListElm *element;
  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (graph->match(data1, ((AdjList *)list_data(element))->vertex))
      break;
  }
  if (element == NULL)
    return 0;

  return set_is_member(&((AdjList *)list_data(element))->adjacent, data2);
}
