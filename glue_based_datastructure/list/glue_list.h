#pragma once
#include "../node/glue_node.h"
#include "../emp/emp.h"

typedef struct glue_list
{
  glue_node_t *head;
} glue_list_t;

void addAtEnd(glue_list_t *l, glue_node_t *newNode);
void printList(glue_list_t *l, void (*printNodeDetails)(glue_node_t *node));