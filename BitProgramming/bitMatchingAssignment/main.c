#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bitsop.h"
#include "bitmap.h"

bitmap_t *initBitMap(int sz)
{
  bitmap_t *ans = malloc(sizeof(bitmap_t));
  int howManyBytes = (sz + 7) / 8;
  ans->bitmap = (char *)malloc(howManyBytes * sizeof(char));
  ans->size = sz;
  return ans;
}

#define ITERATE_BITMAP_BEGIN(bitmap_ptr, bit_state) \
  uint32_t *curr = (uint32_t *)bitmap_ptr->bitmap;  \
  for (int i = 0; i < bitmap_ptr->size; i++)        \
  {                                                 \
    bit_state = ((*curr) >> i) & 1;
#define ITERATE_BITMAP_END(bitmap_ptr, bit_state) \
  }

int main()
{
  bitmap_t *b = initBitMap(20);

  b->bitmap[0] = SET_BIT(b->bitmap[0], 1);
  b->bitmap[0] = SET_BIT(b->bitmap[0], 6);
  b->bitmap[1] = SET_BIT(b->bitmap[1], 2);
  b->bitmap[1] = SET_BIT(b->bitmap[1], 4);

  int *index = malloc(sizeof(int));
  *index = -1;

  char *mask = "0001010x010xx01";

  printf("%d\n", bitmap_pattern_match(b, mask, 15, index));
  printf("ans: %d\n", *index);

  int bitstate = 0;
  ITERATE_BITMAP_BEGIN(b, bitstate)

  ITERATE_BITMAP_END(b, bitstate)
  return 0;
}