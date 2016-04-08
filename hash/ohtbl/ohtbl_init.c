#include "ohtbl.h"

static char vacated;
int ohtbl_init(OHTbl *htbl, int positions, int (*hashingA)(const void *key), 
    int (*hashingB)(const void *key), int (*match)(const void *key1, const void *key2),
    void (*destory)(void *data)) {
  int i;
  if ((htbl->table = (void **)malloc(positions * sizeof(void *))) == NULL)
    return -1;

  htbl->positions = positions;
  for (i = 0; i < htbl->positions; i++)
    htbl->table[i] = NULL;
  
  htbl->vacated = &vacated;
  htbl->hashingA = hashingA;
  htbl->hashingB = hashingB;
  htbl->match = match;
  htbl->destory = destory;
  htbl->size = 0;

  return 0;
}
