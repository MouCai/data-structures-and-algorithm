#include <stdio.h>
#include "heap.h"

int heap_extract(Heap *heap, void **data) {
  void *save, *temp;
  int currentPosition, leftPosition, rightPosition, maximumPosition;
  if (heap_size(heap) == 0)
    return -1;
  *data = heap->tree[0];
  save = heap->tree[heap_size(heap) - 1];
  if (heap_size(heap) - 1 > 0) {
    if ((temp = (void **)realloc(heap->tree, (heap_size(heap) - 1) * sizeof(void *))) == NULL) {
      return -1;
    } else {
      heap->tree = temp;
    }
    heap->size--;
  } else {
    free(heap->tree);
    heap->tree = NULL;
    heap->size = 0;
    return 0;
  }
  
  heap->tree[0] = save;
  currentPosition = 0;
  // leftPosition = heap_left(currentPosition);
  // rightPosition = heap_right(currentPosition);

  while (1) {
    leftPosition = heap_left(currentPosition);
    rightPosition = heap_right(currentPosition);

    if (leftPosition < heap_size(heap) && heap->compare(heap->tree[leftPosition], heap->tree[currentPosition]) > 0) {
      maximumPosition = leftPosition;
    } else {
      maximumPosition = currentPosition;
    }

    if (rightPosition < heap_size(heap) && heap->compare(heap->tree[rightPosition], heap->tree[maximumPosition]) > 0) {
      maximumPosition = rightPosition;
    }

    if (maximumPosition == currentPosition) {
      break;
    } else {
      temp = heap->tree[currentPosition];
      heap->tree[currentPosition] = heap->tree[maximumPosition];
      heap->tree[maximumPosition] = temp;
      currentPosition = maximumPosition;
    }
  }
  return 0;
}
