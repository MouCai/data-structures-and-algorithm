#include "chtbl.h"

int chtbl_init (CHTbl *htbl, int buckets, int (*hashing)(const void *key), 
    int (*match)(const void *key1, const void *key2), void (*destory)(void *data)) {
  int i;
  if ((htbl->table = (List *)malloc(buckets * sizeof(List))) == NULL)
    return -1;
  htbl->buckets = buckets;
  for (i=0; i<buckets; i++)
    list_init(&htbl->table[i], destory, match);
  htbl->hashing = hashing;
  htbl->destory = destory;
  htbl->match = match;
  htbl->size = 0;
  return 0;
}