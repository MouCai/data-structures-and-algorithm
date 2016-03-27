#include "List.h"

NODE DeleteTail(LIST L) {
  NODE T = L->LastNode;
  L->LastNode = L->LastNode->Pred;
  L->LastNode->Succ = (NODE)&L->Tail;
  L->Length--;
  return T;
}
