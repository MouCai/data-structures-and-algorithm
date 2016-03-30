#include "set.h"

static int _remove(Set *set, SetElm *elm, void **data) {
  if (elm == NULL || set_size(set)==0)
    return -1;
  
  *data = elm->data;
  if (elm == set->head) {
    set->head = elm->next;
    if(set->head == NULL)
      set->tail = NULL;
    else
      elm->next->prev = NULL;
  } else {
    elm->prev->next = elm->next;
    if (elm->next == NULL)
      set->tail = elm->prev;
    else
      elm->next->prev = elm->prev;
  }
  free(elm);
  set->size--;
  return 0;
}

void set_destory(Set *set) {
  void *data;
  while (set_size(set)) {
    if (_remove(set, set_tail(set), (void **)&data) == 0 && set->destory != NULL) {
      set->destory(data);
    }
  }
  memset(set, 0, sizeof(Set));
  return;
}
