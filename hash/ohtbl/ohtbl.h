#ifndef _OHTBL_H_
  #define _OHTBL_H_
  #include <stdlib.h>
  #include "../hash.h"
  typedef struct _OHTbl_ {
    int positions;
    void *vacated;
    int (*hashingA)(const void *key);
    int (*hashingB)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destory)(void *data);
    int size;
    void **table;
  } OHTbl;
  
  int ohtbl_init(OHTbl *htbl, int positions, int (*hashingA)(const void *key), 
      int (*hashingB)(const void *key), int (*match)(const void *key1, const void *key2),
      void (*destory)(void *data));
  void ohtbl_destory(OHTbl *htbl);
  int ohtbl_insert(OHTbl *htbl, const void *data);
  int ohtbl_remove(OHTbl *htbl, void **data);
  int ohtbl_lookup(OHTbl *htbl, void **data);

  #define ohtbl_size(htbl) ((htbl)->size)
#endif
