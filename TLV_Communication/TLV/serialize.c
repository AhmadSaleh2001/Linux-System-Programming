#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "serialize.h"

void init_serialized_buffer(ser_buff_t **b)
{
  init_serialized_buffer_of_defined_size(b, SERIALIZE_BUFFER_DEFAULT_SIZE);
}

void init_serialized_buffer_of_defined_size(ser_buff_t **b, int size)
{
  *b = malloc(sizeof(ser_buff_t));
  (*b)->b = malloc(size);
  (*b)->size = size;
  (*b)->nextWrite = 0;
  (*b)->nextRead = 0;
  (*b)->checkpoint = 0;
}

void serialize_string(ser_buff_t *b, char *data, int size)
{

  int available = b->size - b->nextWrite;
  bool bufferSizeChanged = false;
  while (available < size)
  {
    bufferSizeChanged = 1;
    b->size <<= 1;
    available = b->size - b->nextWrite;
  }
  if (!bufferSizeChanged)
  {
    memcpy(b->b + b->nextWrite, data, size);
    b->nextWrite += size;
    return;
  }

  b->b = realloc(b->b, b->size);
  memcpy(b->b + b->nextWrite, data, size);
  b->nextWrite += size;

  return;
}

int is_serialized_buffer_empty(ser_buff_t *b)
{
  return b->nextWrite == 0;
}
void de_serialize_string(char *dest, ser_buff_t *b, int val_size)
{
  memcpy(dest, b->b + b->nextRead, val_size);
  b->nextRead += val_size;
}
void copy_in_serialized_buffer_by_offset(ser_buff_t *b, int size, char *value, int offset)
{
  memcpy(b->b + offset, value, size);
}
void mark_checkpoint_serialize_buffer(ser_buff_t *b)
{
  b->checkpoint = b->nextRead;
}
int get_serialize_buffer_checkpoint_offset(ser_buff_t *b)
{
  int checkpoint = b->checkpoint;
  b->nextRead = b->checkpoint;
  return checkpoint;
}

void serialize_buffer_skip(ser_buff_t *b, int skip_size)
{
  if (b->nextRead + skip_size < 0)
    return;
  bool bufferSizeChanged = false;
  while (b->size < b->nextRead + skip_size)
  {
    b->size <<= 1;
    bufferSizeChanged = 1;
  }
  if (bufferSizeChanged)
  {
    b->b = realloc(b->b, b->size);
  }

  b->nextRead += skip_size;
}

void free_serialize_buffer(ser_buff_t *b)
{
  free(b->b);
  b->checkpoint = b->nextRead = b->nextWrite = b->size = 0;
}

void serialize_integer32(ser_buff_t *b, int *data)
{
  int sizeOf = 4;
  int available = b->size - b->nextWrite;
  bool shouldExtend = 0;
  while (available < sizeOf)
  {
    shouldExtend = 1;
    available = b->size - b->nextWrite;
    b->size <<= 1;
  }
  if (!shouldExtend)
  {
    memcpy(b->b + b->nextWrite, data, sizeOf);
    b->nextWrite += sizeOf;
    return;
  }
  b->b = realloc(b->b, b->size);
  memcpy(b->b + b->nextWrite, (char *)data, sizeOf);
  b->nextWrite += sizeOf;
}
void de_serialize_integer32(int *dest, ser_buff_t *b)
{
  memcpy(dest, b->b + b->nextRead, 4);
  b->nextRead += 4;
}