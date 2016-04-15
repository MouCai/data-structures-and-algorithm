#include "bitree.h"

void bitree_traverse_postorder(BiTreeNode *node, void (*callback)(void *data, void **result), void **result) {
  if (!bitree_is_eob(node)) {
    if (!bitree_is_eob(node->left))
      bitree_traverse_postorder(node->left, callback, result);
    if (!bitree_is_eob(node->right))
      bitree_traverse_postorder(node->right, callback, result);  
    if (node->data != NULL)
      callback(node->data, result);
  }
}
