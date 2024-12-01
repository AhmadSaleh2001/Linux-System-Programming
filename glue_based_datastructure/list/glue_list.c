#include <stdio.h>
#include <stdlib.h>
#include "../node/glue_node.h"
#include "glue_list.h"
#include "../emp/emp.h"

void addAtEnd(glue_list_t *l, glue_node_t *newNode)
{
  newNode->left = NULL;
  newNode->right = NULL;
  if (!l->head)
  {
    l->head = newNode;
    return;
  }
  glue_node_t *curr = l->head;

  while (curr->right != NULL)
  {
    curr = curr->right;
  }
  curr->right = newNode;
}

void printList(glue_list_t *l, void (*printNodeDetails)(glue_node_t *node))
{
  glue_node_t *curr = l->head;
  while (curr != NULL)
  {
    // printf("%p\n", curr);
    printNodeDetails(curr);
    curr = curr->right;
  }
}