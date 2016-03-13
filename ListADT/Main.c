#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(int argc, char **argv) {
  // test IsEmpty
  List Emptylist = malloc(sizeof(List));
  Emptylist->Element = 1;
  Emptylist->Next = NULL;
  printf("'IsEmpty' is pass ? %d\n", IsEmpty(Emptylist));
  free(Emptylist);

  // test NewList
  List newList = NewList();
  printf("'NewList' is pass ? %d\n", IsEmpty(newList));
  free(newList);

  // test Insert 
  Position P = newList;
  Insert(1, newList, P);
  printf("'Insert' is pass ? %d\n", newList->Next->Element);

  return 0;
}
