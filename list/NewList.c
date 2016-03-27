#include "List.h"

LIST NewList() {
  LIST L = malloc(sizeof(struct List));
  if(L) {
    L->Head = (NODE)&L->Tail;
    L->LastNode = (NODE)&L->Head;
    L->Tail = NULL;
    L->Length = 0;
    return L;
  }
  return NULL;
}
