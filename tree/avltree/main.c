#include <stdio.h>
#include "avltree.h"
static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) - (* (int *)key2);
}

static void _callback(void *data, void **result) {
  *(int *)*result = *(int *)((AvlTreeNode *)data)->data;
  int *temp = *result;
  temp++;
  *result = (void *)temp;
  return;
}

int main (int argc, char **argv) {
  AvlTree *testTree1;
  testTree1 = malloc(sizeof(AvlTree));
  avltree_init(testTree1, NULL, _match);

  int testData1 = 1;
  int testData2 = 2;
  int testData3 = 3;
  int testData4 = 4;
  int testData5 = 5;
  int testData6 = 6;
  int testData7 = 7;
  int testData8 = 8;
  void *testPtr1;
  int testArray1[20];

  // test avltree_insert
  testPtr1 = &testData1;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData2;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData3;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData4;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData5;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData6;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData7;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testData8;
  avltree_insert(testTree1, testPtr1);

  testPtr1 = &testArray1[0];
  bitree_traverse_preorder(testTree1->root, _callback, &testPtr1);
  printf("'avltree_insert' is pass ? %d \n", testArray1[0] == 4 &&
                                             testArray1[1] == 2 &&
                                             testArray1[2] == 1 &&
                                             testArray1[3] == 3 &&
                                             testArray1[4] == 6 &&
                                             testArray1[5] == 5 &&
                                             testArray1[6] == 7 &&
                                             testArray1[7] == 8 );
  return 0;
}
