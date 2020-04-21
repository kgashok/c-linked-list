#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *init_list() {
  return NULL;
}

Node *createnode(int data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Node *add(int data, List *list) {
  Node *newnode = createnode(data);
  // is this the first node?
  if (!list) 
    return newnode;
  
  // traverse to the tail
  while (list->next)
      list = list->next;

  list->next = newnode;
  return newnode;
}

void ldisplay(List *list) {
  Node *current = list; 
  printf("List contents [");
  while(current) {
    printf("%d", current->data);
    if (current->next)
      printf(", ");
    current = current->next;
  }
  puts("]");
}

Node *ldelete(int data, List *list) {
  Node *current = list; 
  Node *previous = 0;
  while (current) {
    // is there a match? 
    if (current->data == data) {
      if(previous)
        previous->next = current->next; 
      else  // match at the head node
        list = current->next; 

      free(current);
      return list;
    }  
    // else go check the nextnode 
    previous = current;
    current = current->next;
  }
  printf("%d: No match for data in list!\n", data);
  return list;
}

void ldestroy(List *list) {
  Node *current = list;
  if(!current) 
    return;
  while (current->next) {
    Node *next = current->next;
    free(current);
    current = next;
  }
}

Node *lreverse(List *list) {
  Node *current = list;
  Node *prev = NULL;
  while (current) {
    Node *nextnode = current->next;
    current->next = prev;
    prev = current;
    current = nextnode;
  }
  return prev;
}
