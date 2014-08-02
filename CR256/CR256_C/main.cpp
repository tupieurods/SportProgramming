#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int a[5009];

void ReadData()
{
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

__int64 answer;

__int64 f(int l, int r)
{
  if(l == r)
  {
    return 1;
  }
  __int64 dist = r - l + 1;
  __int64 result = 0;
  int minimal = INT_MAX;
  for(int i = l; i <= r; i++)
  {
    minimal = min(minimal, a[i]);
  }
  result = minimal;
  for(int i = l; i <= r; i++)
  {
    a[i] -= minimal;
  }
  int nl = l, nr = l;
  while(nl <= r)
  {
    while(a[nl] == 0 && nl <= r)
    {
      nl++;
    }
    if(nl > r)
    {
      break;
    }
    nr = nl;
    while(a[nr] != 0 && nr <= r)
    {
      nr++;
    }
    result += f(nl, a[nr] == 0 ? nr - 1 : nr);
    nl = nr;
  }
  return min(result, dist);
}

void Solve()
{
  answer = f(0, n - 1);
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