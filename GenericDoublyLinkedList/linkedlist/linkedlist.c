#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

LinkedList *getLinkedList()
{
  LinkedList *l = calloc(1, sizeof(LinkedList));
  l->head = NULL;
}

void addToFirst(LinkedList *l, void *data)
{
  Node *newHead = calloc(1, sizeof(Node));
  newHead->prev = NULL;
  newHead->next = NULL;
  newHead->data = data;
  if (!l->head)
  {
    l->head = newHead;
  }
  else
  {
    newHead->next = l->head;
    l->head->prev = newHead;
    l->head = newHead;
  }
}

void add(LinkedList *l, void *data)
{
  Node *h = l->head;
  if (!h || l->compareFn(data, (void *)h->data) < 0)
  {
    addToFirst(l, data);
    return;
  }
  Node *prev = NULL;
  Node *newNode = calloc(1, sizeof(Node));
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->data = data;

  while (h)
  {
    int cmp = l->compareFn((void *)newNode->data, (void *)h->data);
    if (cmp < 0)
    {
      newNode->prev = prev;
      newNode->next = h;
      h->prev = newNode;
      return;
    }

    prev = h;
    h = h->next;
  }
  prev->next = newNode;
  newNode->prev = prev;
}

int isEmpty(LinkedList *l)
{
  return l->head == NULL;
}

void printList(LinkedList *l)
{
  Node *t = l->head;
  while (t != NULL)
  {
    l->printFn(t->data);
    t = t->next;
  }
  printf("\n");
}

void registerPrintFunction(LinkedList *l, void (*printFn)(void *data))
{
  l->printFn = printFn;
}
void registerCompareFunction(LinkedList *l, int (*compareFn)(void *std1, void *std2))
{
  l->compareFn = compareFn;
}