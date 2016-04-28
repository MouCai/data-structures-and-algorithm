#include <stdio.h>
#include "heap.h"

static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) - (* (int *)key2);
}

int main (int argc, char **argv) {
  Heap *testHeap1 = (Heap *)malloc(sizeof(Heap));

  // test heap_init
  heap_init(testHeap1, _match, NULL);
  printf("'heap_init' is pass ? %d \n", testHeap1->size == 0 &&
                                        testHeap1->tree == NULL);
  
  return 0;
}
