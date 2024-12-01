#include <stdio.h>
#include <stdint.h>
#include "bitsop.h"

void print_bit_pattern(uint32_t n)
{
  for (int i = 31; i >= 0; i--)
  {
    printf("%d", (n >> i) & 1);
  }
  printf("\n");
}
uint32_t count_bit_set(uint32_t n)
{
  uint32_t ans = 0;
  while (n)
  {
    ans += n & 1;
    n >>= 1;
  }

  return ans;
}

uint32_t rotate(uint32_t n, int k)
{
  while (k > 0)
  {
    k--;
    int bit = n & 1;
    n >>= 1;
    if (bit)
    {
      n |= (1 << 31);
    }
  }
  return n;
}

uint32_t getValueInRange(uint32_t n, int p, int q)
{
  q -= p;
  n >>= p;
  n &= ((1 << (q + 1)) - 1);

  return n;
}