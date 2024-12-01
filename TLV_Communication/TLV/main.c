#include "serialize.h"
#include "TLV1.h"
#include "TLV2.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int getUnitSize(int type)
{
  if (type == 1)
    return sizeof(TLV_t_1);
  return sizeof(TLV_t_2);
}

#define ITERATE_TLV_BEGIN(tlv_ptr, type, count)     \
  int unitSize = getUnitSize(type);                 \
  for (int i = 0; i < count; i++)                   \
  {                                                 \
    char *buffer = malloc(unitSize);                \
    de_serialize_string(buffer, tlv_ptr, unitSize); \
    if (type == 1)                                  \
    {                                               \
      TLV_t_1 *obj = (TLV_t_1 *)buffer;             \
      printDataStd(obj);                            \
    }                                               \
    else                                            \
    {                                               \
      TLV_t_2 *obj = (TLV_t_2 *)buffer;             \
      printDataEmp(obj);                            \
    }

#define ITERATE_TLV_END(tlv_ptr, type, count) \
  }
int main()
{
  ser_buff_t *b;
  int size2Stds = sizeof(TLV_t_1) * 2;
  int size2Emps = sizeof(TLV_t_2) * 2;
  init_serialized_buffer_of_defined_size(&b, 2 + size2Stds + 2 + size2Emps);

  int type1 = 1;
  serialize_string(b, (char *)&type1, 1);
  serialize_string(b, (char *)&size2Stds, 1);
  for (int i = 0; i < 2; i++)
  {
    TLV_t_1 *std1 = malloc(sizeof(TLV_t_1));
    std1->age = i + 20;
    std1->phone = 333 + i;
    memcpy(std1->name, "ahmad", 5);
    serialize_string(b, (char *)std1, getUnitSize(1));
  }

  int type2 = 2;
  serialize_string(b, (char *)&type2, 1);
  serialize_string(b, (char *)&size2Emps, 1);
  for (int i = 0; i < 2; i++)
  {
    TLV_t_2 *emp1 = malloc(sizeof(TLV_t_2));
    emp1->id = i;
    emp1->salary = 3000 + i;
    emp1->tax = 10 + i;
    memcpy(emp1->name, "ahmad emp", 9);
    serialize_string(b, (char *)emp1, getUnitSize(2));
  }

  while (b->nextRead < b->size)
  {
    char *metaData = malloc(sizeof(char) * 2);
    de_serialize_string(metaData, b, 2);
    int type = (int)*metaData;
    int countBytes = (int)*(metaData + 1);
    int typeSize = getUnitSize(type);
    if (type == 0)
      break;
    int count = countBytes / typeSize;
    ITERATE_TLV_BEGIN(b, type, count)
    ITERATE_TLV_END(b, type, count)
  }

  return 0;
}