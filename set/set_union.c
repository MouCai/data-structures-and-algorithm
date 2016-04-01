#include <stdio.h>
#include "set.h"

int set_union (Set *setu, const Set *set1, const Set *set2) {
  SetElm *member;
  set_init(setu, set1->match, NULL);

  for (member=set_head(set1); member != NULL; member = set_next(member)) {
    if (set_insert(setu, set_data(member)) != 0) {
      set_destory(setu);
      return -1;
    }
  }

  for (member=set_head(set2); member != NULL; member = set_next(member)) {
    switch (set_insert(setu, set_data(member))) {
      case 0:
      case 1:
        break;
      case -1:
        set_destory(setu);
        return -1;
        break;
    }
  }
  return 0;
}
