#include "List.h"

Position Find(ElementType X, List L) {
  Position P;
  P = L->Next;
  while (P->Next != NULL && P->Element != X)
    P = P->Next;
  return P;
}
