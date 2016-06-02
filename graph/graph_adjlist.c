#include "graph.h"

int graph_adjlist(Graph *graph, const void *data, AdjList **adjlist) {
  ListElm *element;
  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (graph->match(data, ((AdjList *)list_data(element))->vertex))
      break;
  }
  if (element == NULL)
    return -1;
  *adjlist = list_data(element);
  return 0;
}
