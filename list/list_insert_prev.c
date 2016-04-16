#include "list.h"

int list_insert_prev(List *list, ListElm *elm, const void *data) {
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
    new->next = elm;
    new->prev = elm->prev;
    if (elm->prev == NULL)
      list->head = new;
    else
      elm->prev->next = new;
    elm->prev = new;
  }

  list->size++;
  return 0;
}
