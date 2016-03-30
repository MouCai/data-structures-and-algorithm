#include <stdio.h>
#include "set.h"

int main(int argc, char **argv) {
  Set *TestSet = malloc(sizeof(Set));

  // test set_init
  set_init(TestSet, NULL, NULL);
  printf("'set_init' is pass ? %d \n", TestSet->head == NULL &&
                                       TestSet->tail == NULL &&
                                       TestSet->size == 0);
  // test set_remove
  // TODO

  // test set_is_member
  // TODO
  
  // test set_insert
  // TODO

  // test set_destory
  set_destory(TestSet);
  printf("'set_destory' is pass? %d \n", TestSet->size == 0);
  return 0;
}
