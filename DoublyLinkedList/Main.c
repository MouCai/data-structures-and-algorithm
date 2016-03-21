#include <stdio.h>
#include "DoublyLinkedList.h"

int main(int argc, char **argv) {

  // test NewList
  LIST TestNewList = NewList();
  int TestNewListResult = TestNewList->Tail == NULL && 
                         (int)TestNewList->Head == (int)&TestNewList->Tail &&
                         (int)TestNewList->LastNode == (int)&TestNewList->Head;
  printf("'TestNewList' is pass ? %d \n", TestNewListResult);

  // test GetTail
  NODE TestTailItem = GetTail(TestNewList);
  int TestGetTailResult = TestNewList->LastNode == TestTailItem;
  printf("'GetTail' is pass ? %d \n", TestGetTailResult);
 
  // test GetHead
  NODE TestGetHeadItem = GetHead(TestNewList);
  int TestGetHeadResult = TestNewList->Head == TestGetHeadItem;
  printf("'GetHead' is pass ? %d \n", TestGetHeadResult);

  // test IsEmpty
  printf("'IsEmpty' is pass ? %d \n", IsEmpty(TestNewList));

  // test Prepend
  NODE TestPrependItem = malloc(sizeof(NODE));
  Prepend(TestNewList, TestPrependItem);
  printf("'Prepend' is pass ? %d \n", TestNewList->Head == TestPrependItem && TestPrependItem->Pred->Succ == TestPrependItem);

  

  return 0 ;
}
