#include <stdio.h>
#include "list.h"

int main(int argc, char **argv) {
  // test list_init
  List *testList1 = malloc(sizeof(List));
  list_init(testList1, NULL, NULL);
  printf("'list_init' is pass ? %d \n", testList1->tail == NULL &&
                                        testList1->head == NULL &&
                                        testList1->size == 0); 
  // test list_insert_next
  int testData1 = 1;
  void *testPtr1 = &testData1;
  list_insert_next(testList1, NULL, testPtr1);
  printf("'list_insert_next' is pass ? %d \n", (*(int *)list_data(testList1->tail)) == 1);

  // test list_push
  int testData = 2;
  testPtr1 = &testData;
  list_push(testList1, testPtr1);
  printf("'list_push' is pass ? %d \n", (*(int *)list_data(testList1->tail)) == 2);
  return 0;
}
