#include <stdio.h>
#include <algorithm>

__int64 gcd(__int64 a, __int64 b)
{
  while(b != 0)
  {
    a = a % b;
    std::swap(a, b);
  }
  return a;
}

__int64 lcm(__int64 a, __int64 b)
{
  return a / gcd(a, b) * b;
}



int main()
{
  /*int a, b, c;
  freopen("test.txt", "w", stdout);
  for(int i = 3; i < 100; i++)
  {
  __int64 current = 0;
  for(int f = 1; f <= i; f++)
  {
  for(int s = 1; s <= i; s++)
  {
  for(int t = 1; t <= i; t++)
  {
  __int64 check = lcm(f, lcm(s, t));
  if(check > current)
  {
  current = check;
  a = f;
  b = s;
  c = t;
  }
  }
  }
  }
  printf("%d:\t%d\t%d\t%d:\t%I64d\n", i, a, b, c, current);
  }*/
  int n;
  scanf("%d", &n);
  __int64 answer = 0;
  int start = n - 10;
  if(start <= 0)
    start = 1;
  for(int f = start; f <= n; f++)
  {
    for(int s = start; s <= n; s++)
    {
      for(int t = start; t <= n; t++)
      {
        __int64 check = lcm(f, lcm(s, t));
        if(check > answer)
        {
          answer = check;
        }
      }
    }
  }
  printf("%I64d\n",answer);
  return 0;
}