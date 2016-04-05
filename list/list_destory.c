#include "List.h"

void Destory(LIST L){
  NODE TempCell = L->Head;
  unsigned long Len = L->Length;
  while(Len--) {
    free(TempCell);
    TempCell = TempCell->Succ;
  };
  free(L);
}
