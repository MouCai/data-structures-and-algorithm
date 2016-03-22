#include "DoublyLinkedList.h"

NODE DeleteHead(LIST L) {
  NODE H = L->Head;
  L->Head = L->Head->Succ;
  L->Head->Pred = (NODE)&L->Head;
  return H;
}
