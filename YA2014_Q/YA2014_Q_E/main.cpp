#define LOCAL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#ifndef LOCAL
#include <inttypes.h>
#include <stdint.h>
#define __int64 int64_t
#endif

int n;
__int64 a[1000009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    #ifdef LOCAL
    scanf("%I64d", &a[i]);
    #else
    scanf("%lld", &a[i]);
    #endif
  }
}

__int64 answer;

void Solve()
{
  __int64 minimal = 0, maximal = 0;
  __int64 current = 0;
  for(int i = 1; i <= n; i++)
  {
    if(i % 2 == 1)
    {
      current += a[i - 1];
    }
    else
    {
      current -= a[i - 1];
    }
    minimal = std::min(minimal, current);
    maximal = std::max(maximal, current);
  }
  answer = std::abs(maximal - minimal);
}

void WriteData()
{
  #ifdef LOCAL
  printf("%I64d\n", answer);
  #else
  printf("%lld\n", answer);
  #endif
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}