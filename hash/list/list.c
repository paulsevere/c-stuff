#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
  node* tip;
  node* head;
  node* cursor;
} lst;

node* create_node(char* val) {
  node* head = NULL;
  head = malloc(sizeof(node));
  head->next = NULL;
  char* node_val = malloc(sizeof(char*));
  strcpy(node_val, val);
  head->val = node_val;
  return head;
}

int free_node(node* nd) {
  if (nd->next != NULL) {
    free_node(nd->next);
  }
  free(nd->val);
  free(nd);
  return 1;
}

lst* create_list(char* val) {
  lst* list = malloc(sizeof(lst));
  node* first = create_node(val);
  list->head = first;
  list->cursor = first;
  list->tip = first;
  list->len = 1;
  return list;
}

int push(lst* list, char* n) {
  node* cursor = list->cursor;
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }
  node* new_node = create_node(n);
  cursor->next = new_node;
  list->cursor = new_node;
  list->tip = new_node;
  list->len = list->len + 1;
  return list->len;
}

char* pop(lst* list) {
  node* cursor = list->head;
  while (cursor->next != NULL && cursor->next->next != NULL) {
    cursor = cursor->next;
  }
  char* ret = malloc(sizeof(char*));
  strcpy(ret, cursor->next->val);
  cursor->next = NULL;
  free(cursor->next);
  list->cursor = cursor;
  list->tip = cursor;
  list->len = list->len - 1;
  return ret;
}

int shift(lst* list, char* item) {
  if (list->head->val != NULL) {
    strcpy(item, list->head->val);
  }
  list->head = list->head->next;
  return 1;
}

char* nth(lst* list, int n) {
  node* cursor = list->head;
  int count = 0;
  while (cursor->next != NULL && count < n) {
    count++;
    cursor = cursor->next;
  }
  char* ret = malloc(sizeof(char*));
  strcpy(ret, cursor->val);
  return ret;
}

int set_nth(lst* list, int n, char* val) {
  if (n > list->len - 1) {
    return 0;
  }
  int c = 0;
  node* cursor = list->head;
  while (c < n) {
    cursor = cursor->next;
    c++;
  }
  if (strcpy(cursor->val, val) != NULL) {
    return 1;
  }
  return 0;
}

int insert_nth(lst* list, int n, char* val) {
  node* cursor = list->head;
  int count = 0;
  int inc_length = 0;
  while (count < n - 1) {
    if (cursor->next == NULL) {
      inc_length = 1;
      node* new_node = create_node("");
      cursor->next = new_node;
      cursor = cursor->next;
      list->len++;
      count++;

    } else {
      cursor = cursor->next;
      count++;
    }
  }
  node* new_node = create_node(val);
  new_node->next = cursor->next;
  cursor->next = new_node;

  if (inc_length == 1) {
    list->tip = new_node;
  }

  return list->len;
}

int del_nth(lst* list, int n) {
  node* cursor = list->head;
  int count = 0;
  while (cursor->next != NULL && cursor->next->next != NULL && count < n - 1) {
    cursor = cursor->next;
    count++;
  }
  node* to_be_removed = cursor->next;
  cursor->next = to_be_removed->next;

  list->len = list->len - 1;
  return list->len;
}

int cat_lst(lst* list, lst* other_list) {
  node* cursor = list->cursor;
  while (cursor->next != NULL) {
    cursor = cursor->next;
  }
  list->tip = list->head;

  printf("%s\n", list->tip->val);

  cursor->next = other_list->head;
  list->len = list->len + other_list->len;
  return list->len;
}

void traverse(lst* list) {
  node* cursor = list->head;
  int count = 0;
  while (cursor != NULL) {
    if (strcmp("", cursor->val) != 0) {
      printf("%d : %s\n", count, cursor->val);
    }
    count++;
    cursor = cursor->next;
  }
}

void free_lst(lst* list) {
  node* cursor = list->head;
  free_node(list->head);
}

// void* pop(lst* lst) {}
