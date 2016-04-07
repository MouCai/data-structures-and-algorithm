#include <stdio.h>
#include "chtbl.h"
#include "../hash.h"

int main(int argc, char **argv) {
  // test chtbl_init
  CHTbl *testCHTbl1 = (CHTbl *)malloc(sizeof(CHTbl));
  chtbl_init(testCHTbl1, 10, hash_pjw, NULL, NULL);
  printf("'chtbl_init' is pass ? %d \n", testCHTbl1->table[9].size == 0);

  // test chtbl_destory
  chtbl_destory(testCHTbl1);
  printf("'chtbl_destory' is pass ? %d \n", testCHTbl1->buckets == 0);

  free(testCHTbl1);
  return 0;
}
