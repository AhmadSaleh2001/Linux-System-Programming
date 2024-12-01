#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "../node/glue_node.h"
#include "../generalDefine.h"

glnode_to_object(generateStd, std_t, glnode)

    void print_student_details(glue_node_t **glnode)
{

  std_t *e = generateStd(glnode);

  printf("%d\n", e->age);
  printf("%s\n", e->name);
  printf("%s\n", e->phone);
  printf(" -->\n");
}