#include <stdio.h>
#include "chtbl.h"

int main(int argc, char **argv) {
  CHTbl *testCHTbl1 = (CHTbl *)malloc(sizeof(CHTbl));
  chtbl_init(testCHTbl1, 10, NULL, NULL, NULL);
  printf("'chtbl_init' is pass ? %d \n", testCHTbl1->table[9].size == 0);
  return 0;
}
