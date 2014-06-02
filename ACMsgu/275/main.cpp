#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

//c*n^2 solution

#pragma warning(disable: 4996)

int n;
__int64 a[109];
__int64 powersOf2[65];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &a[i]);
  }
}

__int64 answer;

void Solve()
{
  while(true)
  {
    __int64 maximal = 0;
    int idx = -1;
    for(int i = 0; i < n; i++)
    {
      if(maximal < a[i])
      {
        idx = i;
        maximal = a[i];
      }
    }
    if(idx == -1)
    {
      return;
    }
    answer = std::max(answer, answer ^ maximal);
    //answer ^= maximal;
    a[idx] = 0;
    int k = -1;
    __int64 copy = maximal;
    while(copy != 0)
    {
      copy >>= 1;
      k++;
    }
    for(int i = 0; i < n; i++)
    {
      if((a[i] & (1LL << k)) != 0)
      {
        a[i] ^= maximal;
      }
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  powersOf2[0] = 1;
  powersOf2[1] = 1;
  for(int i = 1; i < 63; i++)
  {
    powersOf2[i + 1] = powersOf2[i] << 1;
  }
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