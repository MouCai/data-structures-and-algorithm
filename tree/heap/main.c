#include <stdio.h>
#include "heap.h"

static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) - (* (int *)key2);
}

int main (int argc, char **argv) {
  Heap *testHeap1 = (Heap *)malloc(sizeof(Heap));
  int testData1 = 90;
  int testData2 = 80;
  int testData3 = 70;
  int testData4 = 60;
  int testData5 = 40;
  int testData6 = 30;
  int testData7 = 20;
  int testData8 = 10;
  int testData9 = 50;
  int testData10 = 85;
  void *testPtr1;
  // test heap_init
  heap_init(testHeap1, _match, NULL);
  printf("'heap_init' is pass ? %d \n", testHeap1->size == 0 &&
                                        testHeap1->tree == NULL);
  // test heap_insert
  testPtr1 = &testData1;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData2;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData3;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData4;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData5;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData6;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData7;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData8;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData9;
  heap_insert(testHeap1, testPtr1);
  testPtr1 = &testData10;
  heap_insert(testHeap1, testPtr1);

  printf("'heap_insert' is pass ? %d \n", testHeap1->size == 10 &&
                                        *(int *)testHeap1->tree[0] == 90 &&
                                        *(int *)testHeap1->tree[1] == 85 &&
                                        *(int *)testHeap1->tree[2] == 70 &&
                                        *(int *)testHeap1->tree[3] == 60 &&
                                        *(int *)testHeap1->tree[4] == 80 &&
                                        *(int *)testHeap1->tree[5] == 30 &&
                                        *(int *)testHeap1->tree[6] == 20 &&
                                        *(int *)testHeap1->tree[7] == 10 &&
                                        *(int *)testHeap1->tree[8] == 50 &&
                                        *(int *)testHeap1->tree[9] == 40);

  return 0;
}
