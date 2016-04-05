#include "list.h"
void list_init(List *list, void (*destory)(void *data), int (*match)(const void *key1, const void *key2)) {
  list->size = 0;
  list->head = 0;
  list->destory = destory;
  list->match = match;
  list->tail = NULL;
  return;
}
