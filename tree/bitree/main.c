#include <stdio.h>
#include "bitree.h"

int main (int argc, char **argv) {
  // test bitree_init
  Bitree *testTree1 = malloc(sizeof(Bitree));
  bitree_init(testTree1, NULL, NULL);
  printf("'bitree_init' is pass ? %d \n", testTree1->size == 0 &&
                                          testTree1->root == NULL);
  
  free(testTree1);
  return 0;
}
