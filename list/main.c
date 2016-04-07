#include <stdio.h>
#include "list.h"
static int _match (const void *key1, const void *key2) {
  return (* (int *)key1) == (* (int *)key2);
}

int main(int argc, char **argv) {
  // test list_init
  List *testList1 = (List *)malloc(sizeof(List));
  list_init(testList1, NULL, _match);
  printf("'list_init' is pass ? %d \n", testList1->tail == NULL &&
                                        testList1->head == NULL &&
                                        testList1->size == 0); 
  // test list_insert_next
  int testData1 = 1;
  void *testPtr1 = &testData1;
  list_insert_next(testList1, NULL, testPtr1);
  printf("'list_insert_next' is pass ? %d \n", (*(int *)list_data(testList1->tail)) == 1);

  // test list_push
  int testData2 = 3;
  testPtr1 = &testData2;
  list_push(testList1, testPtr1);
  printf("'list_push' is pass ? %d \n", (*(int *)list_data(testList1->tail)) == 3);

  // test list_insert_prev
  int testData3 = 2;
  testPtr1 = &testData3;
  list_insert_prev(testList1, testList1->tail, testPtr1);
  printf("'list_insert_prev' is pass ? %d \n", (*(int *)list_data(testList1->tail->prev)) == 2);

  // test list_remove
  testPtr1 = &testData2;
  list_remove(testList1, testList1->tail->prev, &testPtr1);
  printf("'list_remove' is pass ? %d \n", list_size(testList1) == 2 &&
                                          (*(int *)testPtr1) == 2 &&
                                          testList1->head->next == testList1->tail);
      

  // test list_pop
  list_pop(testList1, &testPtr1);
  printf("'list_pop' is pass ? %d \n", list_size(testList1) == 1 &&
                                          (*(int *)testPtr1) == 3 &&
                                          (*(int *)list_data(testList1->tail)) == 1);

  // test list_shift
  list_shift(testList1, &testPtr1);
  printf("'list_shift' is pass ? %d \n", list_size(testList1) == 0 &&
                                          (*(int *)testPtr1) == 1);


  // test list_destory
  list_destory(testList1);
  printf("'list_destory' is pass ? %d \n", list_size(testList1) == 0);

  free(testList1);
  return 0;
}
