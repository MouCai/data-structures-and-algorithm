#include <stdio.h>
#include "bitree.h"

int main (int argc, char **argv) {
  // test bitree_init
  Bitree *testTree1 = malloc(sizeof(Bitree));
  bitree_init(testTree1, NULL, NULL);
  printf("'bitree_init' is pass ? %d \n", testTree1->size == 0 &&
                                          testTree1->root == NULL);
  // test bitree_insert_left
  int testData1 = 1;
  void *testPtr1;
  testPtr1 = &testData1;
  bitree_insert_left(testTree1, NULL, testPtr1);
  printf("'bitree_insert_left' is pass ? %d \n", bitree_data(testTree1->root) == testPtr1);

  // test bitree_insert_right
  int testData2 = 2;
  testPtr1 = &testData2;
  bitree_insert_right(testTree1, testTree1->root, testPtr1);
  printf("'bitree_insert_right' is pass ? %d \n", bitree_data(testTree1->root->right) == testPtr1);

  // test bitree_remove_left & bitree_remove_right
  bitree_insert_right(testTree1, testTree1->root->right, testPtr1);
  bitree_insert_left(testTree1, testTree1->root->right->right, testPtr1);
  bitree_remove_right(testTree1, testTree1->root);
  printf("'bitree_remove_left & bitree_remove_right' is pass ? %d \n", bitree_size(testTree1) == 1);


  // test bitree_destory
  bitree_destory(testTree1);
  printf("'bitree_destory' is pass ? %d \n", bitree_size(testTree1) == 0);

  free(testTree1);
  return 0;
}
