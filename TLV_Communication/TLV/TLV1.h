#pragma once

typedef struct TLV_type_1
{
  char name[30];
  int age;
  int phone;

} TLV_t_1;

void printDataStd(TLV_t_1 *data);