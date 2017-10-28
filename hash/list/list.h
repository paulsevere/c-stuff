typedef union value {
  int i;
  char* s;
} Value;

typedef struct node_t {
  char* val;
  struct node_t* next;
  struct node_t* prev;
} node;

typedef struct list_t {
  int len;
  node* head;
  node* cursor;
  node* tip;
} lst;

node* create_node(char*);

lst* create_list(char*);

int push(lst*, char*);
char* pop(lst*);
char* shift(lst*);
char* nth(lst* head, int n);
int set_nth(lst*, int n, char*);
int insert_nth(lst*, int, char*);
int del_nth(lst*, int);
int cat_lst(lst*, lst*);
void traverse(lst* head);
void free_lst(lst*);
