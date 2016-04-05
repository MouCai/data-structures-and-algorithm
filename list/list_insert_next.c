#include "list.h"

int list_insert_next(List *list, ListElm *elm, const void *data) {
  ListElm *new;

  if (elm == NULL && list_size(list) != 0)
    return -1;

  if ((new = (ListElm *)malloc(sizeof(ListElm))) == NULL)
    return -1;
  
  new->data = (void *)data;

  if (list_size(list) == 0) {
    list->head = new;
    list->tail = new;
    new->next = NULL;
    new->prev = NULL;
  } else {
    new->next = elm->next;
    new->prev = elm;
    if (elm->next == NULL)
      list->tail = new;
    else 
      elm->next->prev = new;
    elm->next = new;
  }

  list->size++;
  return 0;
}
