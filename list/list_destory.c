#include "list.h"

void list_destory(List *list) {
  void *data;
  while (list_size(list)) {
    if (list_remove(list, list_tail(list), (void **)&data) == 0 && list->destory != NULL) {
      list->destory(data);
    }
  }
  memset(list, 0, sizeof(List));
  return;
}
