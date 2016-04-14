#include "bitree.h"

void bitree_traverse_inorder(BiTreeNode *node, void (*callback)(void *data, void **result), void **result) {
  if (bitree_is_eob(node)) {
    return;
  } else {
    if (!bitree_is_eob(node->left))
      bitree_traverse_inorder(node->left, callback, result);
    if (node->data != NULL)
      callback(node->data, result);
    if (!bitree_is_eob(node->right))
      bitree_traverse_inorder(node->right, callback, result);  
  }
}
