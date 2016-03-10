#ifndef _LIST_H
  typedef int ElementType;

  struct Node;
  typedef struct Node *PtrToNode;
  typedef PtrToNode List;
  typedef PtrToNode Position;

  List NewList(void);
  //List MakeEmpty(List L);
  int IsEmpty(List L);
  /*void Append(List L, Node N);
  int IsLast(Position P, List L);
  Position Find(ElementType X, List L);
  void Delete(ElementType X, List L);
  Position FindPrevious(ElementType X, List L);
  void Insert(ElementType X, List L, Position P);
  void DeleteList(List L);
  Position Header(List L);
  Position First(List L);
  Position Advance(Position P);
  ElementType Retrieve(Position P);*/

#endif

struct Node
{
  ElementType Element;
  Position Next;
};
