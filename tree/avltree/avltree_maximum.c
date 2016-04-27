#include "avltree.h"

static int maximum(AvlTree *tree, BiTreeNode *node, void **data) {
  if (bitree_is_eob(tree)) {
    if (((AvlTreeNode *)bitree_data(node))->data != NULL) {
      *data = ((AvlTreeNode *)bitree_data(node))->data;
      return 0;
    } else {
      return -1;
    }
  } else {
    if (bitree_right(node) != NULL) {
      return maximum(tree, bitree_right(node), data);
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

int avltree_maximum(AvlTree *tree, void **data) {
  return maximum(tree, bitree_root(tree), data);
}
