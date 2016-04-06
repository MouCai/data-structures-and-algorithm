#ifndef _HASH_H_
  #define _HASH_H_
  unsigned int hash_pjw(const void *key);
  unsigned int hash_djb(const void *key);
  unsigned int hash_sdbm(const void *key);
#endif
