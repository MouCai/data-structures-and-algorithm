#include "set.h"

int set_intersection(Set *seti, const Set *set1, const Set *set2) {
  SetElm *member;
  set_init(seti, set1->match, NULL);
  for (member=set_head(set1); member != NULL; member = set_next(member)) {
    if (set_is_member(set2, set_data(member))) {
      if (set_insert(seti, set_data(member)) != 0) {
        set_destory(seti);
        return -1;
      }
    }
  }
  return 0;
}
