#include <stdlib.h>
#include "list.h"

int main()
{

  node_t *head = NULL;
  node_t *n1 = allocateNode(10);
  node_t *n2 = allocateNode(20);
  node_t *n3 = allocateNode(99);
  addFirst(&head, n1);
  addFirst(&head, n2);
  addFirst(&head, n3);
  printList(&head);

  return 0;
}