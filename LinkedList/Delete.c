#include "List.h"

void Delete (ElementType X, List L) {
  Position P = L, tempCell;
  while (P->Next != NULL && P->Next->Element != X) {
    P = P->Next;
  }
  if(!IsLast(P, L)){
    tempCell = P->Next;
    P->Next = tempCell->Next;
    free(tempCell);
  }
}
