#include "ohtbl.h"

void ohtbl_destory(OHTbl *htbl) {
  int i;
  if (htbl->destory != NULL) {
    for (i = 0; i < htbl->positions; i++) {
      if (htbl->table[i] != 0 && htbl->table[i] != htbl->vacated)
        htbl->destory(htbl->table[i]);
    }
  }

  free(htbl->table);
  memset(htbl, 0, sizeof(OHTbl));
  return;
}
