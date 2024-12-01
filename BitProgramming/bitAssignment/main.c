#include <stdio.h>
#include "bitsop.h"

#define SET_BIT(n, bit) n |= 1 << bit
#define UNSET_BIT(n, bit) n &= ~(1 << bit)
#define IS_BIT_SET(n, bit) (n >> bit) & 1
#define TOGGLE_BIT(n, bit) n ^= 1 << bit
#define COMPLEMENT(n) ~n

int main()
{
  uint32_t n = 40;
  print_bit_pattern(n);

  SET_BIT(n, 0);
  print_bit_pattern(n);

  UNSET_BIT(n, 0);
  print_bit_pattern(n);

  printf("is set: %d\n", IS_BIT_SET(n, 0));

  TOGGLE_BIT(n, 0);
  print_bit_pattern(n);

  printf("complement: \n");
  print_bit_pattern(COMPLEMENT(n));

  printf("after rotate by 4: \n");
  uint32_t afterRotate = rotate(40, 4);
  print_bit_pattern(afterRotate);

  uint32_t value = 0b00010100000000010000000100000010;
  uint32_t msk = ~((1 << 8) - 1);

  print_bit_pattern(value);
  print_bit_pattern(msk);
  print_bit_pattern(value & msk);

  print_bit_pattern(453452);
  print_bit_pattern(getValue(453452, 3, 7));

  return 0;
}