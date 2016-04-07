#include "chtbl.h"

int chtbl_insert(CHTbl *htbl, const void *data) {
  void *temp;
  int result, bucket;

  temp = (void *)data;
  if (chtbl_lookup(htbl, &temp) == 0)
    return 1;
  bucket = htbl->hashing(data) % chtbl_buckets(htbl);
  if ((result = list_push(&htbl->table[bucket], data)) == 0)
    htbl->size++;
  return result;
}
