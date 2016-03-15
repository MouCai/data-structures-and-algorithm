#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main(int argc, char **argv) {
  // test IsEmpty
  List Emptylist = malloc(sizeof(struct Node));
  Emptylist->Element = 1;
  Emptylist->Next = NULL;
  printf("'IsEmpty' is pass ? %d\n", IsEmpty(Emptylist));
  free(Emptylist);

  // test NewList
  List newList = NewList();
  printf("'NewList' is pass ? %d\n", IsEmpty(newList));

  // test Insert 
  Position P = newList;
  Insert(1, newList, P);
  printf("'Insert' is pass ? %d\n", newList->Next->Element);

  // test IsLast
  Position TestLastPosition = P->Next;
  printf("'IsLast' is pass ? %d\n", IsLast(TestLastPosition, newList));

  // test Find
  Insert(2, newList, TestLastPosition);
  Position TestFindPosition = Find(2, newList);
  printf("'Find' is pass ? %d\n", TestFindPosition->Element == 2);

  // test Delete
  int TestDeleteBeforeLength = 0;
  Position TestDeletePosition = newList;
  while(TestDeletePosition->Next != NULL) {
    TestDeleteBeforeLength++;
    TestDeletePosition = TestDeletePosition->Next;
  }
  Delete(2, newList);
  int TestDeleteAfterLength = 0;
  TestDeletePosition = newList;
  while(TestDeletePosition->Next != NULL) {
    TestDeleteAfterLength++;
    TestDeletePosition = TestDeletePosition->Next;
  }
  printf("'Delete' is pass ? %d\n", (TestDeleteBeforeLength - 1) == TestDeleteAfterLength);
  
  // Test DeleteList
  DeleteList(&newList);
  printf("'DeleteList' is pass ? %d\n'", newList == NULL);
  return 0;
}
