#include "List.h"

NODE DeleteNode (LIST L, NODE N) {
  N->Succ->Pred = N->Pred;
  N->Pred->Succ = N->Succ;
  L->Length--;
  return N;
}
