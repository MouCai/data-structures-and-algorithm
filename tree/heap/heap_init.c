#include "heap.h"

void heap_init(Heap *heap, int (* compare)(const void *key1, const void *key2), void (* destory)(void *data)) {
  heap->compare = compare;
  heap->destory = destory;
  heap->tree = NULL;
  heap->size = 0;
  return;
}
