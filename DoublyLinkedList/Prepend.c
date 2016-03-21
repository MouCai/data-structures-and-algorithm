#include "DoublyLinkedList.h"

NODE Prepend(LIST L, NODE N) {
  N->Succ = L->Head;
  N->Pred = (NODE)&L->Head;
  L->Head->Pred = N;
  L->Head = N;
  return N;
}
