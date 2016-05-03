#ifndef _HEAP_H_
  #define _HEAP_H_
  #include <stdlib.h>
  #include <string.h>
  typedef struct _Heap_ {
    int size;
    int (* compare)(const void *key1, const void *key2);
    void (* destory)(void *data);
    void **tree;
  } Heap;
  void heap_init(Heap *heap, int (* compare)(const void *key1, const void *key2), void (* destory)(void *data));
  void heap_destory(Heap *heap);
  int heap_insert(Heap *heap, const void *data);
  int heap_extract(Heap *heap, void **data);
  #define heap_size(heap) ((heap)->size)
  #define heap_parent(nodePosition) ((int)(((nodePosition) - 1) / 2))
  #define heap_left(nodePosition) (((nodePosition) * 2) + 1)
  #define heap_right(nodePosition) (((nodePosition) * 2) + 2)
#endif
