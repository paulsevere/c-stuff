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
  node* current;
} list;

node* create_node(char*);

int push(node*, char*);
char* pop(node*);
char* shift(list*);
char* nth(node* head, int n);
void traverse(node* head);
