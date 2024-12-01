#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node/glue_node.h"
#include "list/glue_list.h"
#include "emp/emp.h"
#include "std/student.h"

void prepareEmps()
{
    emp_t *e1 = malloc(sizeof(emp_t));
    strcpy(e1->name, "ahmad saleh");
    e1->salary = 20;
    strcpy(e1->address, "nablus");
    e1->empid = 99;
    e1->glnode = malloc(sizeof(glue_node_t));

    emp_t *e2 = malloc(sizeof(emp_t));
    strcpy(e2->name, "ahmad saleh 2");
    e2->salary = 22;
    strcpy(e2->address, "nablus2");
    e2->empid = 111;
    e2->glnode = malloc(sizeof(glue_node_t));

    glue_list_t *l = malloc(sizeof(glue_list_t));
    addAtEnd(l, &e1->glnode);
    addAtEnd(l, &e2->glnode);
    printList(l, print_employee_details);
}

void prepareStds()
{
    std_t *s1 = malloc(sizeof(std_t));
    strcpy(s1->phone, "059111");
    strcpy(s1->name, "ahmad saleh");
    s1->age = 10;
    s1->glnode = malloc(sizeof(glue_node_t));
    // print_student_details(&s1->glnode);

    std_t *s2 = malloc(sizeof(std_t));
    strcpy(s2->phone, "059222");
    strcpy(s2->name, "ali");
    s2->age = 11;
    s2->glnode = malloc(sizeof(glue_node_t));
    // print_student_details(&s2->glnode);

    // printf("%p\n", &s1->glnode);
    // printf("%p\n", &s2->glnode);
    // printf("\n----\n");

    glue_list_t *l = malloc(sizeof(glue_list_t));

    addAtEnd(l, &s1->glnode);
    addAtEnd(l, &s2->glnode);
    printList(l, print_student_details);
}

int main()
{
    // prepareEmps();
    prepareStds();
    return 0;
}