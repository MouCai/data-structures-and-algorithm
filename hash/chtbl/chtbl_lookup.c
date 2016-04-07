#include "chtbl.h"

int chtbl_lookup(CHTbl *htbl, void **data) {
  ListElm *elm;
  int bucket;

  bucket = htbl->hashing(*data) % chtbl_buckets(htbl);
  for (elm = list_head(&htbl->table[bucket]); elm != NULL; elm = list_next(elm)) {
    if (htbl->match(*data, list_data(elm))) {
      *data = list_data(elm);
      return 0;
    }
  }
  return -1;
}
