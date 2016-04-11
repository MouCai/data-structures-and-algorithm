#include "bitree.h"
void bitree_init(Bitree *tree, void (*destory)(void *data), int (*compare)(const void *key1, const void *key2)) {
  tree->size = 0;
  tree->compare = compare;
  tree->destory = destory;
  tree->root = NULL;
  return;
}
