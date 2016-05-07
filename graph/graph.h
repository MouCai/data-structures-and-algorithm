#ifndef _GRAPH_H_
  #define _GRAPH_H_
  #include <stdlib.h>
  #include "list.h"
  #include "set.h"

  typedef struct _AdjList_ {
    void *vertex;
    Set adjacent;
  } AdjList;

  typedef struct _Graph_ {
    int vcount;
    int ecount;
    int (match *)(const void key1, const void key2);
    void (destory *)(void *data);
    List Adjlists;
  } Graph;

#endif
