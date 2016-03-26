#ifndef _DOUBLY_LINKED_LIST_
  #define _DOUBLY_LINKED_LIST_
  #include <stdlib.h>
  struct List {
     struct MNode *Head;
     struct MNode *Tail;
     struct MNode *LastNode;
  };
  
  struct MNode {
     struct MNode *Succ;
     struct MNode *Pred;
  };
  
  typedef struct MNode *NODE;
  typedef struct List *LIST;
  
  LIST NewList(void);
  int IsEmpty(LIST);
  NODE GetTail(LIST);
  NODE GetHead(LIST);
  NODE Append(LIST, NODE);
  NODE Prepend(LIST, NODE);
  NODE DeleteHead(LIST);
  NODE DeleteTail(LIST);
  NODE InsertAfter(LIST, NODE, NODE);
  NODE DeleteNode(LIST, NODE);
  int Push(LIST, NODE);
  NODE Shift(LIST);
  NODE Pop(LIST);
#endif
