#include "bitree.h"

void bitree_traverse_preorder(BiTreeNode *node, void (*callback)(void *data, void **result), void **result) {
  if (bitree_is_eob(node)) {
    return;
  } else {
    if (node->data != NULL)
      callback(node->data, result);
    if (!bitree_is_eob(node->left))
      bitree_traverse_preorder(node->left, callback, result);
    if (!bitree_is_eob(node->right))
      bitree_traverse_preorder(node->right, callback, result);  
  }
}
