#ifndef _AVLTREE_H_
  #define _AVLTREE_H_
  #include "../bitree/bitree.h"
  
  #define AVL_LEFT_HEAVY 1
  #define AVL_BALANCED 0
  #define AVL_RIGHT_HEAVY -1

  typedef struct _AvlTreeNode_ {
    void *data;
    int hidden;
    int factor;
  } AvlTreeNode;

  typedef Bitree AvlTree;

  void avltree_destory(AvlTree *tree);
  int avltree_insert(AvlTree *tree, const void *data);
  int avltree_remove(AvlTree *tree, const void *data);
  int avltree_lookup(AvlTree *tree, void **data);
  int avltree_maximum(AvlTree *tree, void **data);
  int avltree_minimum(AvlTree *tree, void **data);

  #define avltree_init bitree_init
  #define avltree_size(tree) ((tree)->size)
#endif
