#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./list/list.h"

#define MULTIPLIER (91)

unsigned long hash(const char *s) {
  unsigned long h;
  unsigned const char *us;
  us = (unsigned const char *)s;
  h = 0;
  while (*us != '\0') {
    h = h * MULTIPLIER + *us;
    us++;
  }
  return h % 1000;
}

int main(int argc, char **argv) {
  lst *list = create_list("0");
  lst *list_2 = create_list("red");
  for (int x = 1; x < 5; x++) {
    char *num = malloc(sizeof(char *));
    sprintf(num, "%d", x);
    push(list, num);
  }
  push(list_2, "green");
  push(list_2, "yellow");
  cat_lst(list, list_2);
  // insert_nth(list, 100, "ball");

  traverse(list);
  // pop(list);
  printf("%s\n", list->tip->val);

  // list->tip = list_2->tip;

  // printf("%s\n", list->cursor->val);

  free_lst(list);

  return 0;
}
