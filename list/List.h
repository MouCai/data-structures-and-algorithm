#ifndef _DOUBLY_LINKED_LIST_
  #define _DOUBLY_LINKED_LIST_
  #include <stdlib.h>
  struct List {
     struct MNode *Head;
     struct MNode *Tail;
     struct MNode *LastNode;
     unsigned long Length;
  };
  
  struct MNode {
     struct MNode *Succ;
     struct MNode *Pred;
  };
  
  typedef struct MNode *NODE;
  typedef struct List *LIST;
  
  LIST NewList(void);
  NODE Append(LIST, NODE);
  NODE Prepend(LIST, NODE);
  NODE DeleteHead(LIST);
  NODE DeleteTail(LIST);
  NODE InsertAfter(LIST, NODE, NODE);
  NODE DeleteNode(LIST, NODE);
  NODE Push(LIST, NODE);
  
  #define GetTail(LIST) ((LIST)->LastNode)
  #define GetHead(LIST) ((LIST)->Head)
  #define IsEmpty(LIST) ((LIST)->Head->Succ == NULL)
  #define Length(LIST) ((LIST)->Length)
  #define Pop DeleteTail
  #define Shift DeleteHead
#endif
