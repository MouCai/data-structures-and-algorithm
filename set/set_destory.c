#include "set.h"

void set_destory(Set *set) {
  int size = set_size(set);
  SetElm tempCell = set->head;
  while(size--) {
    if(set->destory != NULL)
      set->destory(tempCell);
    free(tempCell);
  }
  free(set);
  return;
}
