#ifndef _BITREE_H_
  #define _BITREE_H_
  #include <stdlib.h>
  #include <string.h>
  typedef struct _BiTreeNode_ {
    void *data;
    struct _BiTreeNode_ *left;
    struct _BiTreeNode_ *right;
  } BiTreeNode;

  typedef struct _Bitree_ {
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destory)(void *data);
    BiTreeNode *root;
  } Bitree;

  void bitree_init(Bitree *tree, void (*destory)(void *data), int (*compare)(const void *key1, const void *key2));
  void bitree_destory(Bitree *tree);
  int bitree_insert_left(Bitree *tree, BiTreeNode *node, const void *data);
  int bitree_insert_right(Bitree *tree, BiTreeNode *node, const void *data);
  void bitree_remove_left(Bitree *tree, BiTreeNode *node);
  void bitree_remove_right(Bitree *tree, BiTreeNode *node);
  int bitree_merge(Bitree *merge, Bitree *left, Bitree *right, const void *data);

  void bitree_traverse_preorder(BiTreeNode *node, void (*callback)(void *data, void **result), void **result);
  void bitree_traverse_inorder(BiTreeNode *node, void (*callback)(void *data, void **result), void **result);
  void bitree_traverse_postorder(BiTreeNode *node, void (*callback)(void *data, void **result), void **result);


  #define bitree_size(tree) ((tree)->size)
  #define bitree_root(tree) ((tree)->root)
  #define bitree_is_eob(node) ((node) == NULL)
  #define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
  #define bitree_left(node) ((node)->left)
  #define bitree_right(node) ((node)->right)
  #define bitree_data(node) ((node)->data)
#endif
