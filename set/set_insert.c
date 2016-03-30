#include "set.h"

int set_insert (Set *set, void *data) {
  SetElm *new = malloc(sizeof(Set));
  if (new == NULL)
    return -1;
  if (set_is_member(set, data))
    return -1;

  new->data = data;
  new->next = NULL;
  new->prev = NULL;

  if (set_is_empty(set)) {
    set->head = new;
    set->tail = new;
  } else {
    set->tail->next = new;
    new->prev = set->tail;
  }
  set->size++;
  return 0;
}
