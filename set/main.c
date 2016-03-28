#include <stdio.h>
#include "set.h"

int main(int argc, char **argv) {
  Set *TestSet = malloc(sizeof(Set));
  set_init(TestSet, NULL, NULL);
  printf("'set_init' is pass ? %d \n", TestSet->head == NULL &&
                                       TestSet->tail == NULL &&
                                       TestSet->size == 0);

  return 0;
}
