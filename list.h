#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

/*
struct list {
  Node *head;
};
*/

typedef struct node List;

//List *makelist();
List *init_list();
Node *createnode(int data);
Node *add(int data, List *list);
Node *ldelete(int data, List *list);
void ldisplay(List *list);
void ldestroy(List *list);
Node *lreverse(List *list);

#endif
