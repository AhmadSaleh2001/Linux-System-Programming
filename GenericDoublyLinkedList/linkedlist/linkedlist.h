typedef struct node
{
  void *data;
  struct node *prev;
  struct node *next;
} Node;

typedef struct linkedlist
{
  Node *head;
  void (*printFn)(void *data);
  int (*compareFn)(void *std1, void *std2);
} LinkedList;

LinkedList *getLinkedList();
void addToFirst(LinkedList *l, void *data);
void add(LinkedList *l, void *data);
void printList(LinkedList *l);
int isEmpty(LinkedList *l);

void registerPrintFunction(LinkedList *l, void (*printFn)(void *data));
void registerCompareFunction(LinkedList *l, int (*compareFn)(void *std1, void *std2));