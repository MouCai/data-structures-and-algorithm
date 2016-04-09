#include <stdio.h>
#include "ohtbl.h"

static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}

int main(int argc, char **argv) {
  // test ohtbl_init
  OHTbl *testOHTbl1 = (OHTbl *)malloc(sizeof(OHTbl));
  ohtbl_init(testOHTbl1, 16, hash_pjw, hash_sdbm, _match, NULL);
  printf("'ohtbl_init' is pass ? %d \n", testOHTbl1->table[9] == NULL);

  // test ohtbl_insert
  int testData1 = 1;
  void *testPtr1;
  testPtr1 = &testData1;
  ohtbl_insert(testOHTbl1, testPtr1);
  printf("'ohtbl_insert' is pass ? %d \n", testOHTbl1->size == 1);

  // test ohtbl_lookup
  int testData2 = 1;
  testPtr1 = &testData2;
  ohtbl_lookup(testOHTbl1, &testPtr1);
  printf("'ohtbl_lookup' is pass ? %d \n", testPtr1 == &testData1);

  // test ohtbl_remove
  testPtr1 = &testData2;
  ohtbl_remove(testOHTbl1, &testPtr1);
  printf("'ohtbl_remove' is pass ? %d \n", testPtr1 == &testData1);

  // test ohtbl_destory
  ohtbl_destory(testOHTbl1);
  printf("'ohtbl_destory' is pass ? %d \n", testOHTbl1->table == 0);

  free(testOHTbl1);
  return 0;
}
