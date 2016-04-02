#include <stdio.h>
#include "set.h"

int set_difference(Set *setd, const Set *set1, const Set *set2) {
  SetElm *member;
  set_init(setd, set1->match, NULL);
  for (member=set_head(set1); member != NULL; member = set_next(member)) {
    if (!set_is_member(set2, set_data(member))) {
      if (set_insert(setd, set_data(member)) != 0) {
        set_destory(setd);
        return -1;
      }
    }
  }
  return 0;
}
