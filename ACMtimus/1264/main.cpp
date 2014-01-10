#include <stdio.h>

int main()
{
  __int64 n, m;
  scanf("%I64d %I64d", &n, &m);
  printf("%I64d", n * (m + 1));
  return 0;
}