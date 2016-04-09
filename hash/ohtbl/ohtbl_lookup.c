#include "ohtbl.h"

int ohtbl_lookup(OHTbl *htbl, void **data) {
  int position, i;
  for (i = 0; i < htbl->positions; i++) {
    position = (htbl->hashingA(*data) + (i * htbl->hashingB(*data))) % htbl->positions;
    if (htbl->table[position] == NULL) {
      return -1;
    } else if (htbl->match(htbl->table[position], *data)) {
      *data = htbl->table[position];
      return 0;
    }
  }
  return -1;
}
