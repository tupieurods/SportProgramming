#include <stdio.h>

using namespace std;

int m;

__int64 binPow(int x, int rate)
{
  if(rate == 0)
    return 1;
  if(rate % 2 == 1)
    return (x * (binPow(x, rate - 1))) % m;
  else
  {
    __int64 tmp = binPow(x, rate / 2);
    return (tmp * tmp) % m;
  }
}

int main()
{
  int n;
  scanf("%d %d", &n, &m);
  __int64 result = binPow(3, n) - 1;
  printf("%I64d", result == -1 ? m - 1 : result);
  return 0;
}
