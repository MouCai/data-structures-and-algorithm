#include "heap.h"

void heap_destory(Heap *heap) {
  int i;
  if (heap->destory != NULL) {
    for (i = 0; i < heap_size(heap); i++) {
      heap->destory(heap->tree[i]);
    }
  }
  free(heap->tree);
  memset(heap, 0, sizeof(Heap));
  return;
}
