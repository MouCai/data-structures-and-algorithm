#include "List.h"

int IsEmpty(LIST L) {
  return L->Head->Succ == NULL;
}
