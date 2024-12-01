#include <stdio.h>
#include <stdlib.h>
#include "emp.h"
#include "../node/glue_node.h"
#include "../generalDefine.h"

glnode_to_object(generateEmp, emp_t, glnode)

    void print_employee_details(glue_node_t **glnode)
{

  emp_t *e = generateEmp(glnode);

  printf("%d\n", e->empid);
  printf("%s\n", e->name);
  printf("%d\n", e->salary);
  printf("%s\n", e->address);
  printf(" -->\n");
}