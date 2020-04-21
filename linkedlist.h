#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct node Node;

typedef struct list List;

List *makelist();
Node *createnode(int data);
void add(int data, List *list);
void ldelete(int data, List *list);
void ldisplay(List *list);
void lreverse(List *list);
void ldestroy(List *list);

#endif
