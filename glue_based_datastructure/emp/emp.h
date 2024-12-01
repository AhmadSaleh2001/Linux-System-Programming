#pragma once
#include "../node/glue_node.h"
typedef struct emp
{

  char name[30]; // 0

  unsigned int salary; // 32

  char address[30]; // 36

  unsigned int empid; // 68

  glue_node_t *glnode; // 72

} emp_t;

void print_employee_details(glue_node_t **glnode);