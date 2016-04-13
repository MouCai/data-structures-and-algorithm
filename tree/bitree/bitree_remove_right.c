#include "bitree.h"

void bitree_remove_right(Bitree *tree, BiTreeNode *node) {
  BiTreeNode **position;

  if (bitree_size(tree) == 0)
    return;

  if (node == NULL)
    position = &tree->root;
  else
    position = &node->right;

  if (*position != NULL) {
    bitree_remove_right(tree, *position);
    bitree_remove_left(tree, *position);
    if (tree->destory != NULL)
      tree->destory((*position)->data);
    free(*position);
    *position = NULL;
    tree->size--;
  }
  return;
}
