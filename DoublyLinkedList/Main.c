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

  // test Append
  NODE TestAppendItem = malloc(sizeof(NODE));
  Append(TestNewList, TestAppendItem);
  printf("'Append' is pass ? %d \n", TestAppendItem->Succ->Pred == TestAppendItem && TestNewList->Tail == NULL);

  // test DeleteHead
  NODE TestDeleteHeadItem = TestNewList->Head;
  printf("'DeleteHead' is pass ? %d \n", TestDeleteHeadItem == DeleteHead(TestNewList) && 
                                         TestDeleteHeadItem->Succ == TestNewList->Head &&
                                         TestDeleteHeadItem->Pred->Succ == TestNewList->Head);

  // test DeleteTail
  NODE TestDeleteTailItem = TestNewList->LastNode;
  printf("'DeleteTail' is pass ? %d \n", TestDeleteTailItem == DeleteTail(TestNewList) && 
                                         TestDeleteTailItem->Succ == (NODE)&TestNewList->Tail &&
                                         TestDeleteTailItem->Succ->Pred == TestNewList->LastNode);

  return 0 ;
}
