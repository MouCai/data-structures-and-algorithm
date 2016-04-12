#include "bitree.h"

int bitree_insert_right(Bitree *tree, BiTreeNode *node, const void *data) {
  BiTreeNode *new, **position;
  if (node == NULL) {
    if (bitree_size(tree) > 0)
      return -1;
    position = &tree->root;
  } else {
    if (bitree_right(node) != NULL)
      return -1;
    position = &bitree_right(node);
  }

  if ((new = malloc(sizeof(BiTreeNode))) == NULL)
    return -1;

  new->data = (void *)data;
  new->left = NULL;
  new->right = NULL;
  *position = new;

  tree->size++;
  return 0;
}
