typedef struct node {
  void * data;
  struct node * prev;
  struct node * next;
} Node;

typedef struct linkedlist {
  Node * head;
} LinkedList;


LinkedList * getLinkedList();
void addToLast(LinkedList * l, void * data);
void printList(LinkedList * l);
int isEmpty(LinkedList * l);
