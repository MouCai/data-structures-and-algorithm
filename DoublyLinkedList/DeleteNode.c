#include "DoublyLinkedList.h"

NODE DeleteNode (LIST L, NODE N) {
  N->Succ->Pred = N->Pred;
  N->Pred->Succ = N->Succ;
  return N;
}
