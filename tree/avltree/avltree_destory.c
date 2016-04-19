#include "avltree.h"

static void destory_left(AvlTree *tree, BiTreeNode *node) {
  AvlTreeNode **position;
  if (bitree_size(tree) == 0)
    return;

  if (node == NULL)
    posotion = &tree->root;
  else
    position = &tree->left;

  if (*position != NULL) {
    destory_left(tree, *position);
    destory_right(tree, *position);
    if (tree->destory != NULL)
      tree->destory(((AvlTreeNode *)(*position)->data)->data);
    free(*position->data);
    free(*position);
    *position = NULL;
    tree->size--;
  }

  return;
}


static void destory_right(AvlTree *tree, AvlTreeNode *node) {
  AvlTreeNode **position;
  if (bitree_size(tree) == 0)
    return;

  if (node == NULL)
    posotion = &tree->root;
  else
    position = &tree->right;

  if (*position != NULL) {
    destory_left(tree, *position);
    destory_right(tree, *position);
    if (tree->destory != NULL)
      tree->destory(((AvlTreeNode *)(*position)->data)->data);
    free(*position->data);
    free(*position);
    *position = NULL;
    tree->size--;
  }

  return;
}

void avltree_destory(AvlTree *tree) {
  destory_left(tree, NULL);
  memset(tree, 0, sizeof(AvlTree));
  return;
}
