#include "avltree.h"

static int lookup (AvlTree *tree, BiTreeNode *node, void **data) {
  int cmpval, retval = -1;
  if (bitree_is_eob(tree))
    return retval;
  cmpval = tree->compare(*data, ((AvlTreeNode *)bitree_data(node))->data);
  if (cmpval < 0) {
    retval = lookup(tree, bitree_left(node), data);
  } else if (cmpval > 0) {
    retval = lookup(tree, bitree_right(node), data);
  } else {
    if (!((AvlTreeNode *)bitree_data(node))->hidden) {
      *data = ((AvlTreeNode *)bitree_data(node))->data;
      retval = 0
    } else {
      retval = -1;
    }
  }
  return retval;
}

int avltree_lookup(AvlTree *tree, void **data) {
  return lookup(tree, bitree_root(tree), data);
}
