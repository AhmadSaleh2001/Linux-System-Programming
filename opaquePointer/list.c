#include <stdlib.h>
#include "list.h"
struct node
{
  int data;
  node_t *left;
  node_t *right;
};

void addFirst(node_t **head, node_t *newNode)
{
  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    newNode->right = *head;
    (*head)->left = newNode;
    *head = newNode;
  }
}
void printList(node_t **head)
{
  node_t *curr = *head;

  int cnt = 0;
  while (cnt++ < 3 && curr != NULL)
  {
    printf("%d ", curr->data);
    curr = curr->right;
  }
}

node_t *allocateNode(int value)
{
  node_t *t = malloc(sizeof(node_t));
  t->data = value;
  t->left = NULL;
  t->right = NULL;
  return t;
}