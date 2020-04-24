#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void){
  List * list = init_list();
  add(1, list);
  add(20, list);
  add(2, list);
  add(5, list);
  add(8, list);
  add(9, list);
  add(13, list);
  ldisplay(list);

  printf("Deleting 2...");
  ldelete(2, list);
  ldisplay(list);

  printf("Deleting 1...");
  ldelete(1, list);
  ldisplay(list);

  printf("Deleting 20...");
  ldelete(20, list);
  ldisplay(list);

  lreverse(list);
  printf("reversed: \n");
  ldisplay(list);

  lreverse(list);
  printf("reversed again!: \n");
  ldisplay(list);

  ldestroy(list);
  puts("Entire list destroyed successfully!");
  return 0;
}
