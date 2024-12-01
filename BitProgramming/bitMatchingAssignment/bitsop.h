#pragma once
#include <stdio.h>
#include <stdint.h>

#define SET_BIT(n, bit) n |= 1 << bit
#define UNSET_BIT(n, bit) n &= ~(1 << bit)
#define IS_BIT_SET(n, bit) (n >> bit) & 1
#define TOGGLE_BIT(n, bit) n ^= 1 << bit
#define COMPLEMENT(n) ~n

void print_bit_pattern(uint32_t n);
uint32_t count_bit_set(uint32_t n);
uint32_t rotate(uint32_t n, int k);
uint32_t getValueInRange(uint32_t n, int p, int q);