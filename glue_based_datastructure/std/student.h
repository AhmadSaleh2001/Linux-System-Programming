#pragma once
#include "../node/glue_node.h"
typedef struct std
{

  char name[30];
  char phone[30];
  int age;
  glue_node_t *glnode;

} std_t;

void print_student_details(glue_node_t **glnode);