#pragma once

typedef struct node node_t;

void addFirst(node_t **head, node_t *newNode);
void printList(node_t **head);
node_t *allocateNode();
