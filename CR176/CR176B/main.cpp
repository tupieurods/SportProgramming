#include <stdio.h>

using namespace std;

int main()
{
  __int64 n, k;
  scanf("%I64d %I64d", &n, &k);
  if(n == 1)
  {
    printf("0");
    return 0;
  }
  if(k >= n)
  {
    printf("1");
    return 0;
  }
  if(((k + 1) * (k - 2)) < 2LL * (n - 2LL))
  {
    printf("-1");
    return 0;
  }
  __int64 answer = 1LL;
  __int64 left = 1LL;
  __int64 right = k - 1LL;
  while(left < right)
  {
    __int64 center = left + (right - left) / 2;
    __int64 from = k - center + 1;
    __int64 to = k - 1;
    __int64 cnt = center - 1;
    __int64 freeToUse = k - center + 1;
    if((cnt * (from + to)) / 2 + freeToUse < n)
    {
      left = center + 1;
    }
    else
    {
      right = center;
    }
  }
  answer = left;
  printf("%I64d", answer);
  return 0;
}
