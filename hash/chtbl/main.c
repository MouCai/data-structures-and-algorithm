#include <stdio.h>
#include "chtbl.h"
#include "../hash.h"
static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}
int main(int argc, char **argv) {
  // test chtbl_init
  CHTbl *testCHTbl1 = (CHTbl *)malloc(sizeof(CHTbl));
  chtbl_init(testCHTbl1, 10, hash_pjw, _match, NULL);
  printf("'chtbl_init' is pass ? %d \n", testCHTbl1->table[9].size == 0);

  // test chtbl_insert
  int testData1 = 1;
  void *testPtr1;
  testPtr1 = &testData1;
  chtbl_insert(testCHTbl1, testPtr1);
  printf("'chtbl_insert' is pass ? %d \n", testCHTbl1->size == 1);
  
  // test chtbl_lookup
  int testData2 = 1;
  int testData3 = 2;
  void *testPtr2;
  testPtr1 = &testData2;
  testPtr2 = &testData3;
  chtbl_lookup(testCHTbl1, &testPtr1);
  printf("'chtbl_lookup' is pass ? %d \n", testPtr1 == &testData1 &&
                                           chtbl_lookup(testCHTbl1, &testPtr2) == -1);

  // test chtbl_destory
  chtbl_destory(testCHTbl1);
  printf("'chtbl_destory' is pass ? %d \n", testCHTbl1->buckets == 0);

  free(testCHTbl1);
  return 0;
}
