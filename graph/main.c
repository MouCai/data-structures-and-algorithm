#include <stdio.h>
#include "graph.h"
static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}
int main (int argc, char **argv) {
  Graph *testGraph1 = (Graph *)malloc(sizeof(Graph));
  int testData1 = 0;
  int testData2 = 1;
  int testData3 = 2;
  void *testPtr1;
  void *testPtr2;

  graph_init(testGraph1, _match, NULL);
  printf("'graph_init' is pass ? %d \n", testGraph1->vcount == 0 &&
                                         testGraph1->ecount == 0 &&
                                         testGraph1->destory == NULL);
  
  testPtr1 = &testData1;
  graph_insert_vertex(testGraph1, testPtr1);
  testPtr2 = &testData2;
  graph_insert_vertex(testGraph1, testPtr2);
  testPtr2 = &testData3;
  graph_insert_vertex(testGraph1, testPtr2);
  printf("'graph_insert_vertex' is pass ? %d \n", testGraph1->vcount == 3 &&
                                                  testGraph1->ecount == 0 &&
                                                  testGraph1->destory == NULL);


  testPtr2 = &testData2;
  graph_insert_edge(testGraph1, testPtr1, testPtr2);
  printf("'graph_insert_edge' is pass ? %d \n", testGraph1->vcount == 3 &&
                                                testGraph1->ecount == 1);

  testPtr2 = &testData3;
  graph_remove_vertex(testGraph1, &testPtr2);
  printf("'graph_remove_vertex' is pass ? %d \n", testGraph1->vcount == 2 &&
                                                  testGraph1->ecount == 1);


  graph_destory(testGraph1);
  printf("'graph_destory' is pass ? %d \n", testGraph1->vcount == 0 &&
                                            testGraph1->ecount == 0 &&
                                            testGraph1->destory == 0); 
  return 0;
}
