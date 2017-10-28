#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union value_t {
  int i;
  char* s;
} value;

typedef struct node_t {
  char* val;
  struct node_t* next;
  struct node_t* prev;
} node;

typedef struct list_t {
  int len;
  node* head;
  node* current;
} list;

node* create_node(char* val) {
  node* head = NULL;
  head = malloc(sizeof(node));
  head->next = NULL;
  char* node_val = malloc(sizeof(char*));
  strcpy(node_val, val);
  head->val = node_val;
  return head;
}

int push(node* head, char* n) {
  node* cursor = head;
  int count = 0;
  while (cursor->next != NULL) {
    cursor = cursor->next;
    count++;
  }
  node* new_node = create_node(n);
  cursor->next = new_node;
  return count;
}

char* pop(node* head) {
  node* cursor = head;
  while (cursor->next != NULL && cursor->next->next != NULL) {
    cursor = cursor->next;
  }
  char* ret = malloc(sizeof(char*));
  strcpy(ret, cursor->next->val);
  cursor->next = NULL;
  free(cursor->next);
  // cursor = NULL;
  return ret;
}

int shift(list* lst, char* item) {
  if (lst->head->val != NULL) {
    strcpy(item, lst->head->val);
  }
  lst->head = lst->head->next;
  return 1;
}

char* nth(node* head, int n) {
  node* cursor = head;
  int count = 0;
  while (cursor->next != NULL && count < n) {
    count++;
    cursor = cursor->next;
  }
  char* ret = malloc(sizeof(char*));
  strcpy(ret, cursor->val);
  return ret;
}

void traverse(node* head) {
  node* cursor = head;
  int count = 0;
  while (cursor != NULL) {
    count++;
    printf("%s\n", cursor->val);
    cursor = cursor->next;
  }
}

// void* pop(List* list) {}
