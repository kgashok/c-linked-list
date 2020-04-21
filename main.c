#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(void){
  List * list = 0;
  list = add(1, list);
  add(20, list);
  add(2, list);
  add(5, list);
  add(8, list);
  add(9, list);
  add(13, list);
  puts("Linked List built successfully!");
  ldisplay(list);

  printf("Deleting 2...");
  list = ldelete(2, list);
  ldisplay(list);
  
  printf("Deleting 1...");
  list = ldelete(1, list);
  ldisplay(list);

  printf("Deleting 20...");
  list = ldelete(20, list);
  ldisplay(list);

  printf("Deleting 120...");
  list = ldelete(120, list);
  ldisplay(list);

  printf("Deleting 13...");
  list = ldelete(13, list);
  ldisplay(list);

  list = lreverse(list);
  printf("reversed: \n");
  ldisplay(list);
  list = lreverse(list);
  printf("reversed again: \n");
  ldisplay(list);

  ldestroy(list);
  puts("Entire list destroyed successfully!");
  return 0;
}
