#include <stdio.h>
#include <cstdlib>

using namespace std;

int n, m;

int inline calcS(int w, int h)
{
  return (2 * w + 1) * (2 * h + 1);
}

int inline max(int first, int second)
{
  return first > second ? first : second;
}

int inline f(int a, int b)
{
  if((2 * a + 1 > n) || (2 * b + 1 > m))
    return 0;
  return (n - (2 * a + 1) + 1) * (m - (2 * b + 1) + 1);
}

int main()
{
  int s;
  scanf("%d %d %d", &n, &m, &s);
  int maxA = n % 2 == 0 ? n / 2 - 1 : n / 2;
  int maxB = m % 2 == 0 ? m / 2 - 1 : m / 2;
  int maxC = maxA;
  __int64 count = 0;
  for(int a = 0; a <= maxA; a++)
    {
      for(int b = 0; b <= maxB; b++)
        {
          int currentS = calcS(a, b);
          if(currentS > s)
            continue;
          if(currentS == s)
            {
              count += f(a, b) * (a + 1) * (b + 1);
              continue;
            }
          int deltaS = s - currentS;
          for(int c = 0; c <= maxC; c++)
            {
              if(c <= a)
                {
                  //Из формулы: s-currentS=2(2c+1)(d-b)
                  if(deltaS % (4 * c + 2) == 0)
                    count += f(max(a, c), max(b, deltaS / (4 * c + 2) + b));
                }
              else
                {
                  //Предположим что d<=b
                  //Формула s-currentS=2d(c-a);
                  if((deltaS - 2 * (c - a)) % (4 * (c - a)) == 0)
                    {
                      int d = (deltaS - 2 * (c - a)) / (4 * (c - a));
                      if(d <= b)
                        {
                          count += f(max(a, c), max(b, d));
                          continue;
                        }
                    }
                  //Предположим что d>b
                  //формула s=(2c+1)(2d+1)
                  if((s - 2 * c - 1) % (4 * c + 2) == 0)
                    {
                      int d = (s - 2 * c - 1) / (4 * c + 2);
                      if(d > b)
                        count += f(max(a, c), max(b, d));
                    }
                }
            }
        }
    }
  printf("%I64d", count);
  return 0;
}
