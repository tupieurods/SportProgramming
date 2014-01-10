#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
__int64 h[100009], p[100009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &h[i]);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%I64d", &p[i]);
  }
}

int compare(const void *v1, const void *v2)
{
  if(*(__int64*)v1 > *(__int64*)v2)
  {
    return 1;
  }
  else if(*(__int64*)v1 < *(__int64*)v2)
  {
    return -1;
  }
  return 0;
}

__int64 answer;

bool check(__int64 value)
{
  int j = 0;
  for(int i = 0; i < n; i++)
  {
    __int64 r;
    if(abs(h[i] - p[j]) > value)
    {
      continue;
    }
    if(h[i] > p[j])
    {
      r = h[i] + max(value - (h[i] - p[j]) * 2, (value - (h[i] - p[j])) / 2);
    }
    else
    {
      r = h[i] + value;
    }
    while(j < m && p[j] <= r)
    {
      j++;
    }
    if(j == m)
    {
      break;
    }
  }
  return j == m;
}

void Solve()
{
  qsort(h, n, sizeof(__int64), compare);
  qsort(p, m, sizeof(__int64), compare);
  __int64 l = 0LL, r = 40000000000LL;
  while(l < r)
  {
    __int64 center = l + (r - l) / 2LL;
    answer = center;
    if(check(center))
    {
      r = center;
    }
    else
    {
      l = center + 1;
    }
  }
  answer = l;
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