#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

LinkedList * getLinkedList() {
  LinkedList * l = calloc(1, sizeof(LinkedList));
  l->head = NULL;
}

void addToLast(LinkedList * l, void * data) {
  Node * newHead = calloc(1, sizeof(Node));
  newHead->prev = NULL;
  newHead->next = NULL;
  newHead->data = data;
  if(!l->head){
    l->head = newHead;
  } else {
    newHead->next = l->head;
    l->head->prev = newHead;
    l->head = newHead;
  }
}

int isEmpty(LinkedList * l) {
  return l->head == NULL;
}

void printList(LinkedList * l) {
  int cnt = 0;
  Node * t = l->head;
  while(t != NULL) {
    int * pc = (int*)(t->data);
    printf("%d -> ", *pc);
    t = t->next;
  }
  printf("\n");
}