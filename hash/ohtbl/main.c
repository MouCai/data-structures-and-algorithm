#include <stdio.h>
#include "ohtbl.h"

static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}

int main(int argc, char **argv) {
  // test ohtbl_init
  OHTbl *testOHTbl1 = (OHTbl *)malloc(sizeof(OHTbl));
  ohtbl_init(testOHTbl1, 10, hash_pjw, hash_sdbm, _match, NULL);
  printf("'ohtbl_init' is pass ? %d \n", testOHTbl1->table[9] == NULL);
  return 0;
}
