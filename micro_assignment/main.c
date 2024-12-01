#include <stdlib.h>

#define BEGIN_ARRAY(arrPtr, arrSz, startIdx, scanVal)              \
  {                                                                \
    int nxt = 0;                                                   \
    for (int i = startIdx, cnt = 0; cnt < scanVal; i = nxt, cnt++) \
    {                                                              \
      nxt = i + 1;                                                 \
      nxt %= arrSz;

#define END_ARRAY \
  }               \
  }

int main()
{

  int sz = 10;
  int *arr = malloc(sz * sizeof(int));
  for (int i = 0; i < sz; i++)
    arr[i] = i + 1;

  int i;
  BEGIN_ARRAY(arr, sz, 5, 10)
  {
    printf("%d ", arr[i]);
  }
  END_ARRAY;

  return 0;
}