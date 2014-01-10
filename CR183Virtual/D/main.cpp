#include <stdio.h>

int n, m, x, y, a, b;
double x1, y1, x2, y2;

void ReadData()
{
  scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &a, &b);
}

int gcd(int v1, int v2)
{
  if(v2 == 0)
    return v1;
  return gcd(v2, v1 % v2);
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

void Solve()
{
  int gcdResult = gcd(a, b);
  a /= gcdResult;
  b /= gcdResult;//Сократили дробь, если возможно
  int t = min(n / a, m / b);//Нашли во сколько максимально раз можно увеличить
  a *= t;
  b *= t;
  x1 = x - a / 2.0;
  y1 = y - b / 2.0;
  x2 = x + a / 2.0;
  y2 = y + b / 2.0;
  if(x1 < 0.0)
  {
    x2 -= x1;
    x1 = 0.0;
  }
  else if(x2 > n)
  {
    x1 -= x2 - n;
    x2 = n;
  }
  if(y1 < 0.0)
  {
    y2 -= y1;
    y1 = 0;
  }
  else if(y2 > m)
  {
    y1 -= y2 - m;
    y2 = m;
  }
}

void WriteData()
{
  printf("%d %d %d %d\n", (int)x1, (int)y1, (int)x2, (int)y2);
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}