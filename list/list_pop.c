#include "list.h"

int list_pop(List *list, void **data) {
  return list_remove(list, list->tail, data);
}
