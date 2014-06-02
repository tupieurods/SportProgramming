#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

//#define LOCAL

int n, a, b;

void ReadData()
{
  scanf("%d %d %d", &n, &a, &b);
}

int a1, a2;

void Solve()
{
  a1 = std::max(0, a - b);
  a2 = (n - a - b);
  if(a2 > 0)
  {
    a2 = a;
  }
  else
  {
    a2 += a;
  }
}

void WriteData()
{
  printf("%d %d\n", a1, a2);
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}