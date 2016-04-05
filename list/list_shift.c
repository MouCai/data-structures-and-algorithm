#include "list.h"

int list_shift(List *list, void **data) {
  return list_remove(list, list->head, data);
}
