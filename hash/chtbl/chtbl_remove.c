#include "chtbl.h"

int chtbl_remove(CHTbl *htbl, void **data) {
  ListElm *elm;
  int bucket;

  bucket = htbl->hashing(*data) % chtbl_buckets(htbl);

  for (elm = list_head(&htbl->table[bucket]); elm != NULL; elm = list_next(elm)) {
    if (htbl->match(*data, list_data(elm))) {
      if (list_remove(&htbl->table[bucket], elm, data) == 0) {
        htbl->size--;
        return 0;
      } else {
        return -1;
      }
    }
  }

  return -1;
}
