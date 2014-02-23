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
  int a[2][109];
  for(int T = 0; T < QWE; T++)
  {
    int first = 0, second = 1;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &a[first][i]);
    }
    for(int i = 0; i < 200; i++)
    {
      std::sort(a[first], a[first] + n);
      bool flag = true;
      for(int j = n - 1; j >= 0; j--)
      {
        for(int k = j - 1; k >= 0; k--)
        {
          if(a[first][j] > a[first][k])
          {
            a[second][j] = a[first][j] - a[first][k];
            flag = false;
          }
          else
          {
            a[second][j] = a[first][j];
          }
        }
      }
      a[second][0] = a[first][0];
      if(flag)
      {
        printf("%d\n", a[first][0] * n);
        break;
      }
      std::swap(first, second);
    }
  }
  return 0;
}