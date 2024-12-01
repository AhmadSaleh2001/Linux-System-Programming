#include "TLV2.h"
#include <stdlib.h>
#include <stdio.h>

void printDataEmp(TLV_t_2 *data)
{
  printf("employee info\n");
  printf("id: %d\n", data->id);
  printf("name: %s\n", data->name);
  printf("salary: %d\n", data->salary);
  printf("tax: %d\n", data->tax);
  printf("\n############\n");
}