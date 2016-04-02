#include <stdio.h>
#include "set.h"

static int _match (const void *key1, const void *key2) {
  const int* ip1 = key1;
  const int* ip2 = key2;
  if (*ip1 == *ip2)
    return 1;
  return 0;
}

int main(int argc, char **argv) {
  Set *testSet = malloc(sizeof(Set));

  // test set_init
  set_init(testSet, _match, NULL);
  printf("'set_init' is pass ? %d \n", testSet->head == NULL &&
                                       testSet->tail == NULL &&
                                       testSet->size == 0);
  // test set_insert
  int testData1 = 1;
  int testData2 = 1;
  set_insert(testSet, &testData1);
  set_insert(testSet, &testData2);
  printf("'set_insert' is pass ? %d \n", set_size(testSet) == 1);
  


  // test set_is_member
  int testData3 = 1;
  printf("'set_is_member' is pass ? %d \n", set_is_member(testSet, &testData3) == 1);
 

  // test set_remove
  void *testPtr1;
  int testData4 = 1;
  testPtr1 = &testData4;
  set_remove(testSet, &testPtr1);
  printf("'set_remove' is pass ? %d \n", set_size(testSet) == 0);


  // test set_union;
  Set *testSet2 = malloc(sizeof(Set));
  set_init(testSet2, _match, NULL);

  Set *testSet3 = malloc(sizeof(Set));
  set_init(testSet3, _match, NULL);

  Set *testSetu = malloc(sizeof(Set));

  int testData5 = 1;
  int testData6 = 2;
  int testData7 = 3;

  int testData8 = 3;
  int testData9 = 4;

  set_insert(testSet2, &testData5);
  set_insert(testSet2, &testData6);
  set_insert(testSet2, &testData7);
 
  set_insert(testSet3, &testData8);
  set_insert(testSet3, &testData9);

  set_union(testSetu, testSet2, testSet3);
  printf("'set_union' is pass? %d \n", testSetu->size == 4);

  // test set_is_equal
  set_insert(testSet2, &testData9);
  printf("'set_is_equal' is pass? %d \n", set_is_equal(testSet2, testSetu));

  // test set_intersection
  testPtr1 = &testData9;
  set_remove(testSet2, &testPtr1);
  Set *testSeti = malloc(sizeof(Set));
  set_intersection(testSeti, testSet2, testSetu);
  printf("'set_intersection' is pass? %d \n", set_is_member(testSeti, &testData7) &&
                                              set_is_member(testSeti, &testData8));
  
  // test set_is_subset
  printf("'set_is_subset' is pass? %d \n", set_is_subset(testSet3, testSetu));

  // test set_difference
  Set *testSetd = malloc(sizeof(Set));
  set_difference(testSetd, testSet2, testSet3);
  printf("'set_difference' is pass? %d \n", set_is_member(testSetd, &testData5) &&
                                            set_is_member(testSetd, &testData6));

  // test set_destory
  set_destory(testSet);
  set_destory(testSet2);
  set_destory(testSet3);
  set_destory(testSetu);
  set_destory(testSeti);
  set_destory(testSetd);
  printf("'set_destory' is pass? %d \n", testSet->size == 0);
  return 0;
}
