#include <stdlib.h>
#include "List.h"

void DeleteList (List *L) {
  List Temp = *L;
  Position P = Temp;
  while(P != NULL){
    Temp = P->Next;
    free(P);
    P = NULL;
    P = Temp;
  }
  *L = NULL;
}
