#ifndef _LIST_
  #define _LIST_ 1;
  typedef int ElementType;

  struct Node;
  typedef struct Node *PtrToNode;
  typedef PtrToNode List;
  typedef PtrToNode Position;

  List NewList(void);
  int IsEmpty(List L);
  
  int IsLast(Position P, List L);
  Position Find(ElementType X, List L);
  void Delete(ElementType X, List L);
  void Insert(ElementType X, List L, Position P);
  void DeleteList(List *L);
  ElementType Retrieve(Position P);

#endif

struct Node
{
  ElementType Element;
  Position Next;
};
