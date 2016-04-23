#include <stdio.h>
#include "avltree.h"
static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) - (* (int *)key2);
}
int main (int argc, char **argv) {
  AvlTree *testTree1;
  testTree1 = malloc(sizeof(AvlTree));
  avltree_init(testTree1, NULL, _match);


  return 0;
}
