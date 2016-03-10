#include <stdlib.h>
#include "List.h"

List NewList () {
  List L = malloc(sizeof(struct Node));
  if(L){
    L->Element = 0;
    L->Next = NULL;
    return L;
  }
  return NULL;
}
