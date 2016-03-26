#include "list.h"

NODE Push(LIST L, NODE N){
  L->LastNode->Succ = N;
  N->Pred = L->LastNode;
  N->Succ = (NODE)&L->Tail;
  L->LastNode = N;
  return N;
}
