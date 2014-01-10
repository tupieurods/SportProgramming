#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int n;
  scanf("%d", &n);
  __int64 a[2][11];
  memset(a, 0, sizeof(a));
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    if(val >= 0)
    {
      a[0][val]++;
    }
    else
    {
      a[1][-val]++;
    }
  }
  __int64 answer = 0LL;
  for(int i = 1; i < 11; i++)
  {
    answer += a[0][i] * a[1][i];
  }
  answer += (a[0][0] - 1) * (a[0][0])/ 2LL;
  printf("%I64d\n", answer);
  return 0;
}