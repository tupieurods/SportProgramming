#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int a, b, w, x, c;

void ReadData()
{
  scanf("%d %d %d %d %d", &a, &b, &w, &x, &c);
}

__int64 answer;
int aDecreasing;
int periodLen;

bool check(__int64 value)
{
  __int64 cnt = value % periodLen;
  __int64 checker = aDecreasing * (value / periodLen);
  for(int i = 0; i < cnt; i++)
  {
    if(b >= x)
    {
      b -= x;
    }
    else
    {
      b = b - x + w;
      checker++;
    }
  }
  return c - value <= a - checker;
}

void Solve()
{
  answer = 0;
  int ca = a, cb = b, cw = w, cx = x, cc = c;
  aDecreasing = 0;
  periodLen = 0;
  do
  {
    periodLen++;
    if(b >= x)
    {
      b -= x;
    }
    else
    {
      b = b - x + w;
      aDecreasing++;
    }
  }while(cb != b);
  __int64 l = 0, r = 1LL << 50;
  while(r - l > 5)
  {
    __int64 mid = (l + r) / 2;
    if(check(mid))
    {
      r = mid;
    }
    else
    {
      l = mid;
    }
    b = cb;
  }
  for(; l <= r; l++)
  {
    if(check(l))
    {
      answer = l;
      break;
    }
    b = cb;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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