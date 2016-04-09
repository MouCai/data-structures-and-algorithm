#include "ohtbl.h"

int ohtbl_insert(OHTbl *htbl, const void *data) {
  int position, i;
  void *temp;

  if (htbl->size == htbl->positions)
    return -1;

  temp = (void *)data;
  if (ohtbl_lookup(htbl, &temp) == 0)
    return 1;

  for (i = 0; i < htbl->positions; i++) {
    position = (htbl->hashingA(data) + (i * htbl->hashingB(data))) % htbl->positions;
    if (htbl->table[position] == NULL || htbl->table[position] == htbl->vacated) {
      htbl->table[position] = (void *)data;
      htbl->size++;
      return 0;
    }
  }
  return -1;
}
