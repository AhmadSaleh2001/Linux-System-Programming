#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct bitmap
{
  char *bitmap;
  uint32_t size;
} bitmap_t;

bool bitmap_is_full(bitmap_t *bitmap);
bool bitmap_pattern_match(bitmap_t *bitmap, char *binary_string, int n_bits, int *i);
