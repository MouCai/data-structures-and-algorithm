#include <stdlib.h>
#include <stdio.h>
#include "List.h"

List NewList () {
  List L = malloc(sizeof(struct Node));

  if(L == NULL) {
    printf("out of space");
    exit(1);
  }
  L->Element = 0;
  L->Next = NULL;
  return L;
}
