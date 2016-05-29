#include "set.h"

int set_insert (Set *set, const void *data) {
  SetElm *new;

  if (set_is_member(set, data))
    return 1;

  new = (SetElm *)malloc(sizeof(SetElm));
  if (new == NULL)
    return -1;
  new->data = (void *)data;
  new->next = NULL;
  new->prev = NULL;

  if (set_is_empty(set)) {
    set->head = new;
    set->tail = new;
  } else {
    set->tail->next = new;
    new->prev = set->tail;
    set->tail = new;
  }
  set->size++;
  return 0;
}
