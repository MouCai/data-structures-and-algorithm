#include "heap.h"

int heap_insert(Heap *heap, const void *data) {
  void *temp;
  int currentPosition,parentPosition;
  if ((temp = (void **)realloc(heap->tree, (heap_size(heap)+1) * sizeof(void *))) == NULL) {
    return -1;
  } else {
    heap->tree = temp;
  }
  heap->tree[heap_size(heap)] = (void *)data;
  currentPosition = heap_size(heap);
  parentPosition = heap_parent(currentPosition);

  while (currentPosition > 0 && heap->compare(heap->tree[parentPosition], heap->tree[currentPosition]) < 0) {
    temp = heap->tree[currentPosition];
    heap->tree[currentPosition] = heap->tree[parentPosition];
    heap->tree[parentPosition] = temp;
    
    currentPosition = parentPosition;
    parentPosition = heap_parent(currentPosition);
  }

  heap->size++;
  return 0;
}
