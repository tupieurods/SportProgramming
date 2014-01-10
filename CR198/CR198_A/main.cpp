#include <stdio.h>
#include <stdlib.h>
//TL
int x, y, a, b, m;

int f(int l, int r)
{
  int result = 0;
  for(int i = l; i <= r; i++)
  {
    //if(i % x == 0 && i % y == 0)
    if(i % (x * y) == 0)
    {
      result++;
    }
  }
  return result;
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  while(scanf("%d %d %d %d", &x, &y, &a, &b) != -1)
  {
    int answer = 0;
    bool flag = true;
    if(x != 1)
    {
      for(int i = 2; i <= x; i++)
      {
        if(x % i == 0)
        {
          int cnt = 0;
          int copy = y;
          while(copy % i == 0)
          {
            cnt++;
            copy /= i;
          }
          for(int j = 0; j < cnt; j++)
          {
            if(x % i == 0)
            {
              x /= i;
            }
          }
        }
      }
    }
    //answer = f(1, b);
    //answer -= f(1, a - 1);
    answer = b / (x * y);
    answer -= (a - 1) / (x * y);
    printf("%d\n", answer);
  }
  return 0;
}