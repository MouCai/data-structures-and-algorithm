#include "bitree.h"

void bitree_destory(Bitree *tree) {
  bitree_remove_right(tree, NULL);
  memset(tree, 0, sizeof(Bitree));
  return;
}
