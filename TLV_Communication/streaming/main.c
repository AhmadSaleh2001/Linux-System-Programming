#include "serialize.h"
#include <stdlib.h>
#include <string.h>

int main()
{

  ser_buff_t *b = NULL;
  init_serialized_buffer(&b);
  serialize_string(b, "ahmad", 5);
  serialize_string(b, "ali", 3);
  serialize_string(b, "mahmoud", 7);

  int x1 = 55;
  int x2 = 99;
  int *ptr1 = &x1;
  int *ptr2 = &x2;
  serialize_integer32(b, ptr1);
  serialize_integer32(b, ptr2);

  char *output1 = (char *)malloc(sizeof(char) * 50);
  de_serialize_string(output1, b, 5);
  printf("%s\n", output1);

  serialize_buffer_skip(b, 3);

  char *output2 = (char *)malloc(sizeof(char) * 50);
  de_serialize_string(output2, b, 7);
  printf("%s\n", output2);

  int *int1 = malloc(sizeof(int));
  de_serialize_integer32(int1, b);
  printf("%d\n", *int1);

  int *int2 = malloc(sizeof(int));
  de_serialize_integer32(int2, b);
  printf("%d\n", *int2);

  return 0;
}