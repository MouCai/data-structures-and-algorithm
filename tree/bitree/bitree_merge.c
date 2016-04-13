#include "bitree.h"

int bitree_merge(Bitree *merge, Bitree *left, Bitree *right, const void *data) {
  bitree_init(merge, NULL, NULL);
  if (bitree_insert_left(merge, NULL, data) != 0) {
    bitree_destory(merge);
    return -1;
  }

  bitree_root(merge)->left = bitree_root(left);
  bitree_root(merge)->right = bitree_root(right);

  merge->size += bitree_size(left) + bitree_size(right);

  left->root = NULL;
  left->size = 0;
  right->root = NULL;
  right->size = 0;

  return 0;
}
