#include <stdlib.h>
#include <stdio.h>
#include "List.h"

void Insert(ElementType X, List L, Position P) {
  Position TempCell;
  TempCell = malloc(sizeof(struct Node));
  if(TempCell == NULL) {
    printf("out of space");
  }
  TempCell->Next = P->Next;
  TempCell->Element = X;
  P->Next = TempCell;
}
