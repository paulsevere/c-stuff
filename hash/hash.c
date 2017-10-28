#include <stdio.h>
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
  node *head = create_node("one");
  list *lst = malloc(sizeof(list));
  lst->head = head;
  printf("List head%s\n", lst->head->val);
  push(head, "two");
  push(head, "three");

  traverse(head);
  char *cool = nth(head, 0);
  char *rad = pop(head);

  printf("VALUE at %d: %s\n", 0, cool);
  traverse(head);

  return 0;
}
