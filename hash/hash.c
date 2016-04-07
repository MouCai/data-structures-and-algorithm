#include "hash.h"
int hash_pjw(const void *key) {
  const char *ptr;
  int val;
  
  val = 0;
  ptr = key;

  while (*ptr != '\0') {
    unsigned int temp;
    val = (val << 4) + (*ptr);
    if ((temp = (val & 0xf0000000)) != 0) {
      val = val ^ (temp >> 24);
      val = val ^ temp;
    }
    ptr++;
  }
  return val;
}

int hash_sdbm(const void *key) {
  const char *ptr;
  int val;

  val = 0;
  ptr = key;

  while (*ptr != '\0') {
    val = *ptr + (val << 6) + (val << 16) - val;
    ptr++;
  }

  return val;
}
