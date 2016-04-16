#include "list.h"

void list_each(List *list, void (*callback)(void *data, void **result), void **result) {
  ListElm *temp;
  if (callback == NULL || result == NULL)
    return;
  for (temp = list_head(list); temp != NULL; temp = list_next(temp)) {
    callback(list_data(temp), result);
  }
  return;
}
