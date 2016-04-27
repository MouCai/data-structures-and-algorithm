#include "avltree.h"

static int minimum(AvlTree *tree, BiTreeNode *node, void **data) {
  if (bitree_is_eob(tree)) {
    if (((AvlTreeNode *)bitree_data(node))->data != NULL) {
      *data = ((AvlTreeNode *)bitree_data(node))->data;
      return 0;
    } else {
      return -1;
    }
  } else {
    if (bitree_left(node) != NULL) {
      return minimum(tree, bitree_left(node), data);
    } else {
      if (((AvlTreeNode *)bitree_data(node))->data != NULL) {
        *data = ((AvlTreeNode *)bitree_data(node))->data;
        return 0;
      } else {
        return -1;
      }
    }
  }
}

int avltree_minimum(AvlTree *tree, void **data) {
  return minimum(tree, bitree_root(tree), data);
}
