#include "employee.h"
void printEmployee(void *data)
{
  Employee *e = (Employee *)data;
  printf("employee id: %d  ", e->id);
  printf("employee name: %s  ", e->name);
  printf("employee phone: %d  ", e->phone);
  printf(" --> ");
}