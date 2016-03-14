#include <stdlib.h>
#include "List.h"

Position Find(ElementType X, List L) {
  Position P;
  P = L->Next;
  while (P->Next != NULL)
    P = P->Next; 
  return P;
}
