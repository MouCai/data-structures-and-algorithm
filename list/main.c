#include <stdio.h>
#include "List.h"

int main(int argc, char **argv) {
  // test list_init
  List *testList1 = malloc(sizeof(List));
  list_init(testList1, NULL, NULL);
  printf("'list_init' is pass ? %d \n", testList1->tail == NULL &&
                                        testList1->head == NULL &&
                                        testList1->size == 0); 
  return 0 ;
}
