#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable: 4996)

int n;

void ReadData()
{
  scanf("%d", &n);
}

bool used[19];
int current[19], best[19];
int resBest;

void f(int step)
{
  if(step == n + 1)
  {
    int resCurrent = 0;
    for(int i = 0; i <= n; i++)
    {
      resCurrent += i ^ current[i];
    }
    if(resCurrent > resBest)
    {
      resBest = resCurrent;
      memcpy(best, current, sizeof(current));
    }
    return;
  }
  for(int i = 0; i <= n; i++)
  {
    if(!used[i])
    {
      used[i] = true;
      current[step] = i;
      f(step + 1);
      used[i] = false;
    }
  }
}

__int64 answer;
int p[1000009];

void Solve()
{
  /*resBest = 0;
  memset(used, 0, sizeof(used));
  f(0);
  printf("%d\n", resBest);
  for(int i = 0; i <= n; i++)
  {
    printf("%d ", best[i]);
  }*/
  memset(p, 0, sizeof(p));
  answer = n * 1LL * (n + 1);
  int nBackup = n;
  while(n > 0)
  {
    int copy = n;
    int m = 1;
    while(copy != 0)
    {
      copy >>= 1;
      m <<= 1;
    }
    m >>= 1;
    int l = 0, r = 1;
    while(m + l <= n && m - r >= 0)
    {
      p[m + l] = m - r;
      p[m - r] = m + l;
      l++;
      r++;
    }
    n = m - r;
  }
  n = nBackup;
}

void WriteData()
{
  printf("%I64d\n", answer);
  for(int i = 0; i <= n; i++)
  {
    printf("%d ", p[i]);
  }
  printf("\n");
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