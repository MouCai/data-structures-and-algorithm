#include <stdio.h>
#include "DoublyLinkedList.h"

int main(int argc, char **argv) {
  // test NewList
  LIST TestNewList = NewList();
  int TestNewListResult = TestNewList->Tail == NULL && 
                         (int)TestNewList->Head == (int)&TestNewList->Tail &&
                         (int)TestNewList->LastNode == (int)&TestNewList->Head;
  printf("'TestNewList' is pass ? %d \n", TestNewListResult);

  
  return 0 ;
}
