#include "avltree.h"

static void rotate_left(BiTreeNode **node) {
  BitreeNode *left, *grandchild;
  left = bitree_left(node);
  if (((AvlTreeNode *)bitree_data(left))->factor == AVL_LEFT_HEAVY) {
    bitree_left(*node) = bitree_right(left);
    bitree_right(left) = *node;
    ((AvlTreeNode *)bitree_data(node))->factor = AVL_BALANCED;
    ((AvlTreeNode *)bitree_data(left))->factor = AVL_BALANCED;
    *node = left;
  } else {
    grandchild = bitree_right(left);
    bitree_right(left) = bitree_left(grandchild);
    bitree_left(grandchild) = left;
    bitree_left(*node) = bitree_right(grandchild);
    bitree_right(grandchild) = *node;
    switch (((AvlTreeNode *)bitree_data(grandchild))->factor) {
      case AVL_LEFT_HEAVY:
        ((AvlTreeNode *)bitree_data(node))->factor = AVL_RIGHT_HEAVY;
        ((AvlTreeNode *)bitree_data(left))->factor = AVL_BALANCED;
        break;
      case AVL_BALANCED:
        ((AvlTreeNode *)bitree_data(node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(left))->factor = AVL_BALANCED;
        break;
      case AVL_RIGHT_HEAVY:
        ((AvlTreeNode *)bitree_data(node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(left))->factor = AVL_LEFT_HEAVY;
        break;
    }
    ((AvlTreeNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
  }
  return;
}

static void rotate_right(BiTreeNode **node) {
  BitreeNode *right, *grandchild;
  right = bitree_right(node);
  if (((AvlTreeNode *)bitree_data(left))->factor == AVL_RIGHT_HEAVY) {
    bitree_right(*node) = bitree_left(right);
    bitree_left(right) = *node;
    ((AvlTreeNode *)bitree_data(node))->factor = AVL_BALANCED;
    ((AvlTreeNode *)bitree_data(right))->factor = AVL_BALANCED;
    *node = right;
  } else {
    grandchild = bitree_left(right);
    bitree_left(right) = bitree_right(grandchild)
    bitree_right(grandchild) = right;
    bitree_right(node*) = bitree_left(grandchild)
    bitree_left(grandchild) = *node;
    switch (((AvlTreeNode *)bitree_data(grandchild))->factor) {
      case AVL_LEFT_HEAVY:
        ((AvlTreeNode *)bitree_data(node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(right))->factor = AVL_RIGHT_HEAVY;
        break;
      case AVL_BALANCED:
        ((AvlTreeNode *)bitree_data(node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(right))->factor = AVL_BALANCED;
        break;
      case AVL_RIGHT_HEAVY:
        ((AvlTreeNode *)bitree_data(node))->factor = AVL_LEFT_HEAVY;
        ((AvlTreeNode *)bitree_data(right))->factor = AVL_BALANCED;
        break;
    }
    ((AvlTreeNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
  }
  return;
}

int avltree_insert(AvlTree *tree, const void *data) {
  return 0;
}
