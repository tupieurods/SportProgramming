#include <stdio.h>
#include <string.h>

const int maximal = 3000000;

int main()
{
  __int64 n;
  scanf("%I64d", &n);
  bool *a = new bool[maximal + 1];
  memset(a, true, sizeof(bool) * (maximal + 1));
  int cnt = 0;
  for(int i = 2; i <= maximal; i++)
  {
    if(a[i])
    {
      printf("%d ", i);
      cnt++;
      if(cnt == n)
      {
        break;
      }
      if((__int64)i * i <= maximal)
      {
        for(int j = i * i; j <= maximal; j += i)
        {
          a[j] = false;
        }
      }
    }
  }
  return 0;
}