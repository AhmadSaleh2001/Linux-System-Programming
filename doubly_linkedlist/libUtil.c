#include "DoublyLinkedList.h"
void change(LinkedList * l) {
  Node * h = l->head;
  while(h){
    int * val = ((int *)h->data);
    *val = 99;
    h->data = (void *)val;
    h = h->next;
  }
}