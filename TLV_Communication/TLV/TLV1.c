#include "TLV1.h"
#include <stdlib.h>
#include <stdio.h>

void printDataStd(TLV_t_1 *data)
{
  printf("student info\n");
  printf("name: %s\n", data->name);
  printf("age: %d\n", data->age);
  printf("phone: %d\n", data->phone);
  printf("\n----------\n");
}