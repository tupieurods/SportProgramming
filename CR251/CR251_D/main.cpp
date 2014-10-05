#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

#pragma warning(disable: 4996)

int n, m;
int a[100009], b[100009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }
}

__int64 answer;
__int64 suma[100009], sumb[100009];
map<int, int> ma, mb;

__int64 f(__int64 v)
{
  __int64 result = 0;
  for(int i = 0; i < n; i++)
  {
    if(a[i] < v)
    {
      result += v - a[i];
    }
  }
  for(int i = 0; i < m; i++)
  {
    if(b[i] > v)
    {
      result += b[i] - v;
    }
  }
  return result;
}

void Solve()
{
  answer = _I64_MAX;
  __int64 l = 1, r = 1000000000LL;
  while(r - l > 10)
  {
    int g = l + (r - l) / 3LL;
    int h = l + 2LL * (r - l) / 3LL;
    if(f(g) < f(h))
    {
      r = h;
    }
    else
    {
      l = g;
    }
  }
  for(; l <= r; l++)
  {
    answer = min(answer, f(l));
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
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