#include "graph.h"

int graph_remove_vertex(Graph *graph, void **data) {
  ListElm *element, *temp, *prev;
  AdjList *adjlist;
  int found;

  prev = NULL;
  found = 0;

  for (element = list_head(&graph->adjlists); element != NULL; element = list_next(element)) {
    if (set_is_member(&((AdjList *)list_data(element))->adjacent, *data))
      return -1;

    if (graph->match(*data, ((AdjList *)list_data(element))->vertex)) {
      temp = element;
      found = 1;
    }

    if (!found)
      prev = element;
  }

  if (!found)
    return -1;

  if (set_size(&((AdjList *)list_data(element))->adjacent) > 0)
    return -1;

  if (list_remove(&graph->adjlists, element, (void **)&adjlist) != 0)
    return -1;

  *data = adjlist->vertex;
  free(adjlist);

  graph->ecount--;
  return 0;
}
