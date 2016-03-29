#ifndef _SET_
  #define _SET_
  #include <stdlib.h>
  typedef struct _SetElm_ {
    void *data;
    struct _SetElm_ *prev;
    struct _SetElm_ *next;
  } SetElm;

  typedef struct _Set_ {
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destory)(void *data);
    SetElm *head;
    SetElm *tail;
  } Set;

  void set_init(Set *set, int (*match)(const void *key1, const void *key2), void (*destory)(void *data));
  void set_destory(Set *set);
  int set_insert(Set *set, void *data);
  int set_remove(Set *set, void **data);
  int set_union(Set *setu, const Set *set1, const Set *set2);
  int set_intersection(Set *seti, const Set *set1, const Set *set2);
  int set_difference(Set *setd, const Set *set1, const Set *set2);
  int set_is_member(const Set *set, const void *data);
  int set_is_subset(const Set *set1, const Set *set2);
  int set_is_equal(const Set *set1, const Set *set2);
  #define set_size(set) ((set)->size)
  #define set_head(set) ((set)->head)
  #define set_tail(set) ((set)->tail)
  #define set_is_empty(set) ((set)->size == 0)
#endif
