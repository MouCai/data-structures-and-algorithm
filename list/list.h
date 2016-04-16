#ifndef _LIST_H_
  #define _LIST_H_
  #include <stdlib.h>
  #include <string.h>
  typedef struct _ListElm_ {
    void *data;
    struct _ListElm_ *prev;
    struct _ListElm_ *next;
  } ListElm;

  typedef struct _List_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destory)(void *data);
    ListElm *head;
    ListElm *tail;
  } List;
  
  void list_init(List *list, void (*destory)(void *data), int (*match)(const void *key1, const void *key2));
  void list_destory(List *list);
  void list_each(List *list, void (*callback)(void *data, void **result), void **result);
  int list_insert_next(List *list, ListElm *elm, const void *data);
  int list_insert_prev(List *list, ListElm *elm, const void *data);
  int list_remove(List *list, ListElm *elm, void **data);
  int list_push(List *list, const void *data);
  int list_pop(List *list, void **data);
  int list_shift(List *list, void **data);

  #define list_tail(List) ((List)->tail)
  #define list_head(List) ((List)->head)
  #define list_is_empty(List) ((List)->head->next == NULL)
  #define list_size(List) ((List)->size)
  #define list_next(ListElm) ((ListElm)->next)
  #define list_prev(ListElm) ((ListElm)->prev)
  #define list_data(ListElm) ((ListElm)->data)
#endif
