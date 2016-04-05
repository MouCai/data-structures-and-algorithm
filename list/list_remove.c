#include "List.h"

int list_remove(List *list, ListElm *elm, void **data) {
  if (elm == NULL || list_size(list) == 0)
    return -1;

  *data = elm->data;

  if (elm == list->head) {
    list->head = elm->next;
    if (elm->next == NULL)
      list->tail = NULL;
    else 
      elm->next->prev = NULL;
  } else {
    elm->prev->next = elm->next;
    if (elm->next == NULL)
      list->tail = elm->prev;
    else
      elm->next->prev = elm->prev;
  }

  free(elm);
  list->size--;
  return 0;
}
