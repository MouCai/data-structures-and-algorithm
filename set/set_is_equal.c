#include "set.h"

int set_is_equal (const Set *set1, const Set *set2) {
  SetElm *member;

  if (set_size(set1) != set_size(set2))
    return 0;
  
  for (member = set_head(set1); member != NULL; member = set_next(member)) {
    if (!set_is_member(set2, set_data(member)))
      return 0;
  }

  return 1;
}
