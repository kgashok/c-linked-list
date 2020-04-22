// Add your includes below
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *lhead = NULL;

int is_valid(Node *n) { return n != NULL; }

Node *traverse(Node *np, int steps) {
  for (; is_valid(np) && steps > 0; np = np->next, steps--)
    ;
  return steps == 0 ? np : NULL;
}

void connect(Node *current, Node *following) {
  if (is_valid(current))
    current->next = following;
}

int get_value() {
  int val;
  printf("\n Enter the data : ");
  scanf("%d", &val);
  printf("%d", val);
  return val;
}

int get_position() {
  int pos;
  printf("\n Enter the position: ");
  scanf("%d", &pos);
  printf("%d", pos);
  pos = pos - 1;
  return pos;
}

Node *getNode() {
  int pos = get_position();
  return traverse(lhead, pos);
}

Node *init_node(int val) {
  Node *np = (Node *)malloc(sizeof(Node));
  np->data = val;
  np->next = NULL;
  return np;
}

void insert_after(Node *locatedNode, int val) {
  Node *next = locatedNode->next;
  Node *newN = init_node(val);
  connect(locatedNode, newN);
  connect(newN, next);
}

void insert() {
  Node *locatedNode = getNode();
  if (is_valid(locatedNode)) {
    int val = get_value();
    insert_after(locatedNode, val);
    return;
  }
  printf("\n No such position");
}

//------- DO NOT EDIT BELOW ---------------
void create();
void ndisplay();
int main() {
  int choice, n;
  printf("\n Enter the initial no. of inputs:");
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++)
    create();
  printf("\n1.Insert"
         "\n3.Display\n6.Exit");
  do {
    printf("\n Enter your choice: ");
    scanf("%d", &choice);
    printf("%d", choice);
    switch (choice) {
    case 1:
      insert();
      break;
    case 3:
      ndisplay();
      break;
    case 6:
      break;
    }
  } while (choice != 6);
  return 0;
}
Node *ltail;
void create() {
  int val = get_value();
  Node *new = init_node(val);
  if (lhead == NULL) {
    lhead = new;
    ltail = lhead;
  } else {
    connect(ltail, new);
    ltail = new;
  }
}
void ndisplay() {
  Node *iter = lhead;
  if (!is_valid(iter))
    printf("\nThe List is empty");
  else {
    printf("\n  The list contains : ");
    for (; is_valid(iter); iter = iter->next)
      printf("\t %d", iter->data);
  }
}