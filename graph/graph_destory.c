#include "graph.h"

void graph_destory(Graph *graph) {
  AdjList *adjlist;
  
  while (list_size(&graph->adjlists) > 0) {
    if (list_remove(&graph->adjlists, list_head(&graph->adjlists), (void **)&adjlist) == 0) {
      set_destory(&adjlist->adjacent);
      if (graph != NULL)
        graph->destory(adjlist->vertex);
      free(adjlist);
    }
  }

  list_destory(&graph->adjlists);
  memset(graph, 0, sizeof(Graph));
  return;
}
