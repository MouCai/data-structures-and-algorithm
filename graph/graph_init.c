#include "graph.h"

void graph_init(Graph *graph, int (match *)(const void *key1, const void *key2), void (destory *)(void *data)) {
  graph->vcount = 0;
  graph->ecount = 0;
  graph->match = match;
  graph->destory = destory;
  list_init(&graph->Adjlists, NULL);
}
