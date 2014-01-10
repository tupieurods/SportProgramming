#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    int maxA = -1, minA = 109;
    for(int i = 0; i < n; i++)
    {
      int val;
      scanf("%d", &val);
      maxA = std::max(maxA, val);
      minA = std::min(minA, val);
    }
    int minB = 109;
    for(int i = 0; i < m; i++)
    {
      int val;
      scanf("%d", &val);
      minB = std::min(minB, val);
    }
    int v = 1;
    for(; v < 1000; v++)
    {
      if(v >= maxA && 2 * minA <= v && minB > v)
      {
        break;
      }
    }
    if(v == 1000)
    {
      printf("-1\n");
    }
    else
    {
      printf("%d\n", v);
    }
  }
  return 0;
}