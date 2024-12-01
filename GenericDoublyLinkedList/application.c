#include "linkedlist/linkedlist.h"
#include "student/student.h"
#include "employee/employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void testStudent()
{
    LinkedList *l = getLinkedList();
    registerPrintFunction(l, printStudent);
    registerCompareFunction(l, compareStudents);

    Student *s1 = (Student *)(malloc(sizeof(Student)));
    s1->id = 1;
    s1->name = (char *)"ahmad";

    Student *s2 = (Student *)(malloc(sizeof(Student)));
    s2->id = 2;
    s2->name = (char *)"ali";

    Student *s3 = (Student *)(malloc(sizeof(Student)));
    s3->id = 3;
    s3->name = (char *)"masddhmoud";

    // addToFirst(l, s1);
    // addToFirst(l, s2);
    // addToFirst(l, s3);
    add(l, s3);
    add(l, s2);
    add(l, s1);
    printList(l);
}

int main()
{
    testStudent();

    return 0;
}