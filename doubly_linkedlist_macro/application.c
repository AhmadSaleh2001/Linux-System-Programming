#include "DoublyLinkedList.h"
#include "Tree.h"
#include "libUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define START_LOOP_LINKEDLIST(listptr)                     \
    {                                                      \
        Node *temp = listptr->head;                        \
        for (Node *t = listptr->head; t != NULL; t = temp) \
        {                                                  \
            temp = temp->next;

#define END_LOOP_LINKEDLIST \
    }                       \
    }

void printTreeNode(void *data)
{
    int *d = (int *)data;
    printf("%d ", d);
}

int compareFunction(void *data1, void *data2)
{
    int d1 = (int *)data1;
    int d2 = (int *)data2;
    if (d1 > d2)
        return 1;
    return -1;
}
int main()
{
    // LinkedList *l = getLinkedList();
    // int x = 10;
    // int y = 20;
    // int *px = &x;
    // int *py = &y;
    // addToLast(l, (void *)(px));
    // addToLast(l, (void *)(py));

    // START_LOOP_LINKEDLIST(l)
    // {
    //     printf("%d ", *((int *)(t->data)));
    // }
    // END_LOOP_LINKEDLIST;

    BST *b = getBST();
    registerPrintFunction(b, printTreeNode);
    registerCompareFunction(b, compareFunction);

    addToBST(b, (void *)10);
    addToBST(b, (void *)2);
    addToBST(b, (void *)34);
    preorder(b);
    return 0;
}