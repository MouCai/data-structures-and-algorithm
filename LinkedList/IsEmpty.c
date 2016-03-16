#include <stdlib.h>
#include "List.h"

int IsEmpty(List L) {
  return L->Next == NULL;
}
