#include "set.h"

int set_remove (Set *set, void **data) {
  SetElm *member, *prev;
  prev = NULL;
  for (member=set_head(set); member != NULL; member = set_next(member)) {
    if (set->match(*data, member->data))
      break;
    prev = member;
  }
  if (member == NULL)
    return -1;
  
  *data = set_data(member);

  if (prev == NULL) {
    set->head = member->next;
    if (set->head == NULL)
      set->tail = NULL;
    else
      member->next->prev = NULL;
  } else {
    prev->next = member->next;
    if (member->next == NULL)
      set->tail = prev;
    else
      member->next->prev = prev;
  }
  free(member);
  set->size--;
  return 0;
}
