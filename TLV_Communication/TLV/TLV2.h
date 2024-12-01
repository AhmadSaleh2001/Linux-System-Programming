#pragma once

typedef struct TLV_type_2
{
  int id;
  char name[30];
  int salary;
  int tax;

} TLV_t_2;

void printDataEmp(TLV_t_2 *data);