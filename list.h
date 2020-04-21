#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

struct list {
  Node *head;
};

typedef struct list List;


List *makelist();
Node *createnode(int data);
void add(int data, List *list);
void ldelete(int data, List *list);
void ldisplay(List *list);
void lreverse(List *list);
void ldestroy(List *list);

#endif
