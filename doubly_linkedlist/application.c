#include "DoublyLinkedList.h"
#include "libUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
    LinkedList * l = getLinkedList();
    int x = 10;
    int y = 20;
    int *px = &x;
    int *py = &y;
    addToLast(l, (void*)(px));
    addToLast(l, (void*)(py));
    printList(l);

    printf("is Empty: %d\n", isEmpty(l));
    change(l);

    printList(l);
    

    return 0;
}