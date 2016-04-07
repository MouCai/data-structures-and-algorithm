#include "chtbl.h"

void chtbl_destory (CHTbl *htbl) {
  int i;
  for (i = 0; i < htbl->buckets; i++)
    list_destory(&htbl->table[i]);
  free(htbl->table);
  memset(htbl, 0, sizeof(CHTbl));
  return;
}
