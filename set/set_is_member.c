#include "set.h"

int set_is_member (const Set *set, const void *data) {
  SetElm *member;
  for (member = set_head(set); member != NULL; member = set_next(member)) {
    if (set->match(data, set_data(member)))
      return 1;
  }
  return 0;
}
