#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(int argc, char **argv) {
  // test IsEmpty
  List Emplist = malloc(sizeof(List));
  Emplist->Element = 1;
  Emplist->Next = NULL;
  printf("'IsEmpty' is pass ? %d\n", IsEmpty(Emplist));
  return 0;
}
