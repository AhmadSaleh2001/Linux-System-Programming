#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{

    struct node *left;

    struct node *right;

} node_t;

typedef struct emp
{

    char name[30]; // 0

    unsigned int salary; // 32

    char address[30]; // 36

    unsigned int empid; // 68

    node_t *glnode; // 72

} emp_t;

#define offsetof(structName, fieldName) \
    (unsigned int)&(((structName *)0)->fieldName)

#define glnode_to_employee(fnName, structName, fieldName)             \
    static inline structName *fnName(node_t **glnode)                 \
    {                                                                 \
        unsigned int offset_glnode = offsetof(structName, fieldName); \
        unsigned long empOffset = ((char *)glnode - offset_glnode);   \
        structName *e = (structName *)empOffset;                      \
        return e;                                                     \
    }

glnode_to_employee(generateEmp, emp_t, glnode)

    void print_employee_details(node_t **glnode)
{

    emp_t *e = generateEmp(glnode);

    printf("%d\n", e->empid);
    printf("%s\n", e->name);
    printf("%d\n", e->salary);
    printf("%s\n", e->address);
}

static inline void fn()
{
    printf("ahmad");
}

int main()
{

    emp_t *e = malloc(sizeof(emp_t));
    strcpy(e->name, "ahmad saleh");
    e->salary = 20;
    strcpy(e->address, "nablus");
    e->empid = 99;
    e->glnode = malloc(sizeof(node_t));
    print_employee_details(&e->glnode);

    return 0;
}