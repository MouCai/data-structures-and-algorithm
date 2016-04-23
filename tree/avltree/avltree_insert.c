#include "avltree.h"

static void rotate_left(BiTreeNode **node) {
  BiTreeNode *left, *grandchild;
  left = bitree_left(*node);
  if (((AvlTreeNode *)bitree_data(left))->factor == AVL_LEFT_HEAVY) {
    bitree_left(*node) = bitree_right(left);
    bitree_right(left) = *node;
    ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
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
        ((AvlTreeNode *)bitree_data(*node))->factor = AVL_RIGHT_HEAVY;
        ((AvlTreeNode *)bitree_data(left))->factor = AVL_BALANCED;
        break;
      case AVL_BALANCED:
        ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(left))->factor = AVL_BALANCED;
        break;
      case AVL_RIGHT_HEAVY:
        ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(left))->factor = AVL_LEFT_HEAVY;
        break;
    }
    ((AvlTreeNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
  }
  return;
}

static void rotate_right(BiTreeNode **node) {
  BiTreeNode *right, *grandchild;
  right = bitree_right(*node);
  if (((AvlTreeNode *)bitree_data(right))->factor == AVL_RIGHT_HEAVY) {
    bitree_right(*node) = bitree_left(right);
    bitree_left(right) = *node;
    ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
    ((AvlTreeNode *)bitree_data(right))->factor = AVL_BALANCED;
    *node = right;
  } else {
    grandchild = bitree_left(right);
    bitree_left(right) = bitree_right(grandchild);
    bitree_right(grandchild) = right;
    bitree_right(*node) = bitree_left(grandchild);
    bitree_left(grandchild) = *node;
    switch (((AvlTreeNode *)bitree_data(grandchild))->factor) {
      case AVL_LEFT_HEAVY:
        ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(right))->factor = AVL_RIGHT_HEAVY;
        break;
      case AVL_BALANCED:
        ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
        ((AvlTreeNode *)bitree_data(right))->factor = AVL_BALANCED;
        break;
      case AVL_RIGHT_HEAVY:
        ((AvlTreeNode *)bitree_data(*node))->factor = AVL_LEFT_HEAVY;
        ((AvlTreeNode *)bitree_data(right))->factor = AVL_BALANCED;
        break;
    }
    ((AvlTreeNode *)bitree_data(grandchild))->factor = AVL_BALANCED;
    *node = grandchild;
  }
  return;
}

static int insert(Bitree *tree, BiTreeNode **node, const void *data, int *balanced) {
  AvlTreeNode *avlnode;
  int result, compare;
  if (bitree_is_eob(*node)) {
    if ((avlnode = (AvlTreeNode *)malloc(sizeof(AvlTreeNode))) == NULL) 
      return -1;
    avlnode->factor = 0;
    avlnode->data = (void *)data;
    avlnode->hidden = 0;
    return bitree_insert_left(tree, *node, avlnode);
  } else {
    compare = tree->compare(data, ((AvlTreeNode *)bitree_data(*node))->data);

    if (compare < 0) {

      if (bitree_is_eob(bitree_left(*node))) {
        if ((avlnode = (AvlTreeNode *)malloc(sizeof(AvlTreeNode))) == NULL) 
          return -1;
        avlnode->factor = 0;
        avlnode->data = (void *)data;
        avlnode->hidden = 0;
        if (bitree_insert_left(tree, *node, avlnode) != 0)
          return -1;
        *balanced = 0;
      } else {
        if ((result = insert(tree, &bitree_left(*node), data, balanced)) != 0) {
          return result;
        }
      }

      if (!(*balanced)) {
        switch (((AvlTreeNode *)bitree_data(*node))->factor) {
          case AVL_LEFT_HEAVY:
            rotate_left(node);
            *balanced = 1;
            break;
          case AVL_BALANCED:
            ((AvlTreeNode *)bitree_data(*node))->factor = AVL_LEFT_HEAVY;
            break;
          case AVL_RIGHT_HEAVY:
            ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
            *balanced = 1;
            break;
        }
      }

    } else if (compare > 0) {
      
      if (bitree_is_eob(bitree_right(*node))) {
        if ((avlnode = (AvlTreeNode *)malloc(sizeof(AvlTreeNode))) == NULL) 
          return -1;
        avlnode->factor = 0;
        avlnode->data = (void *)data;
        avlnode->hidden = 0;
        if (bitree_insert_right(tree, *node, avlnode) != 0)
          return -1;
        *balanced = 0;
      } else {
        if ((result = insert(tree, &bitree_right(*node), data, balanced)) != 0) {
          return result;
        }
      }

      if (!(*balanced)) {
        switch (((AvlTreeNode *)bitree_data(*node))->factor) {
          case AVL_LEFT_HEAVY:
            ((AvlTreeNode *)bitree_data(*node))->factor = AVL_BALANCED;
            *balanced = 1;
            break;
          case AVL_BALANCED:
            ((AvlTreeNode *)bitree_data(*node))->factor = AVL_RIGHT_HEAVY;
            break;
          case AVL_RIGHT_HEAVY:
            rotate_right(node);
            *balanced = 1;
            break;
        }
      }

    } else {
      if (!((AvlTreeNode *)bitree_data(*node))->hidden) {
        return 1;
      } else {
        if (tree->destory != NULL)
          tree->destory(((AvlTreeNode *)bitree_data(*node))->data);
        ((AvlTreeNode *)bitree_data(*node))->data = (void *)data;
        ((AvlTreeNode *)bitree_data(*node))->hidden = 0;
        *balanced = 1;
      }
    }
  }
  return 0;
}

int avltree_insert(AvlTree *tree, const void *data) {
  int balanced = 0;
  return insert(tree, &bitree_root(tree), data, &balanced);
}
