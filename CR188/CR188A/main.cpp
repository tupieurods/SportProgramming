#include <stdio.h>

int main()
{
  __int64 n, k;
  scanf("%I64d %I64d", &n, &k);
  __int64 t = n / 2;
  __int64 p = n - t;
  __int64 answer = 0;
  if(k <= p)
  {
    answer = 1LL + (k - 1) * 2LL;
  }
  else
  {
    k -= p;
    answer = k * 2LL;
  }
  printf("%I64d", answer);
  return 0;
}