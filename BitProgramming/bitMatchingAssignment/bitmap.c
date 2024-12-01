#include "bitmap.h"
#include "bitsop.h"
#include <stdbool.h>

bool bitmap_is_full(bitmap_t *bitmap)
{
  uint32_t *curr = (uint32_t *)bitmap->bitmap;
  uint32_t msk = (1 << (bitmap->size)) - 1;
  return ((*curr) & msk) == msk;
}
bool bitmap_pattern_match(bitmap_t *bitmap, char *binary_string, int n_bits, int *i)
{
  uint32_t msk = 0;
  uint32_t template = 0;
  for (int i = n_bits - 1; i >= 0; i--)
  {
    if ((int)(binary_string[i]) != (int)'x')
    {
      msk = SET_BIT(msk, (n_bits - 1) - i);
      if (binary_string[i] - '0' == 1)
        template = SET_BIT(template, (n_bits - 1) - i);
    }
  }

  uint32_t *curr = (uint32_t *)bitmap->bitmap;
  // print_bit_pattern(*curr);
  // print_bit_pattern(template);
  // print_bit_pattern(msk);

  for (int j = 0; j <= bitmap->size - n_bits; j++)
  {
    uint32_t current_segment = getValueInRange(*curr, j, j + n_bits - 1);
    // printf("%d %d\n", j, j + n_bits - 1);
    // print_bit_pattern(current_segment);
    // print_bit_pattern(current_segment & msk);
    // print_bit_pattern(template);
    // printf("\n");
    if ((current_segment & msk) == template)
    {
      *i = j;
      return 1;
    }
  }
  return 0;
}