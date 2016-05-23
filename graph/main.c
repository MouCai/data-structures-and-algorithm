#include <stdio.h>
#include "graph.h"
static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}
int main (int argc, char **argv) {
  Graph *testGraph1 = (Graph *)malloc(sizeof(Graph));
  graph_init(testGraph1, _match, NULL);
  printf("'graph_init' is pass ? %d \n", testGraph1->vcount == 0 &&
                                         testGraph1->ecount == 0 &&
                                         testGraph1->destory == NULL); 
  return 0;
}
