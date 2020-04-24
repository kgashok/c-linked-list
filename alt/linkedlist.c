#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List *init_list() {
  List *list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

Node *createnode(int data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void add(int data, List *list) {
  Node *newnode = createnode(data);
  if (list->head == NULL) {
    list->head = newnode;
    return;
  }
  
  Node *current = list->head;
  while (current->next)
    current = current->next;
  current->next = createnode(data);
}

void ldisplay(List *list) {
  Node *current = list->head;
  if (list->head == NULL) {
    puts("Nothing to display!");
    return;
  }

  printf("List contents [");
  for (; current != NULL; current = current->next) {
    printf("%d", current->data);
    if (current->next)
      printf(", ");
  }
  puts("]");
}

void ldestroy(List *list) {
  Node *current = list->head;
  Node *next = current;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

void ldelete(int data, List *list) {
  Node *current = list->head;
  Node *previous = current;
  while (current != NULL) {
    if (current->data == data) {
      previous->next = current->next;
      if (current == list->head)
        list->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void lreverse(List *list) {
  Node *current = list->head;
  Node *prev = NULL;
  while (current) {
    Node *nextnode = current->next;
    current->next = prev;
    prev = current;
    current = nextnode;
  }
  list->head = prev;
}
