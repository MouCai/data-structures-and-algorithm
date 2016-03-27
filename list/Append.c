#include "List.h"
NODE Append(LIST L, NODE N) {
  N->Pred = L->LastNode;
  N->Succ = (NODE)&L->Tail;
  L->LastNode->Succ = N;
  L->LastNode = N;
  L->Length++;
  return N;
}
