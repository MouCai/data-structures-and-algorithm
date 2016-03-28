#include "set.h"

void set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destory)(void *data)) {
  set->size = 0;
  set->destory = destory;
  set->head = NULL;
  set->tail = NULL;
  set->match = match;
  return;
}
