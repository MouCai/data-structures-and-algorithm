#include "list.h"

int list_push(List *list, const void *data) {
  return list_insert_next(list, list_tail(list), data);
}
