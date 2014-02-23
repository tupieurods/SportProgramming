#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

int n;
__int64 a[100009], b[100009], dp[100009];
int ind[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &a[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &b[i]);
  }
}

double getIntersection(int v1, int v2)
{
  return (1.0 * dp[v2] - dp[v1]) / (1.0 * b[v1] - b[v2]);
}

void Solve()
{
  dp[0] = 0;
  ind[0] = 0;
  int l = 0, r = 1;
  for(int i = 1; i < n; i++)
  {
    while(l + 1 < r && getIntersection(ind[l], ind[l + 1]) < a[i])
    {
      l++;
    }
    dp[i] = dp[ind[l]] + a[i] * b[ind[l]];
    while(l + 1 < r && getIntersection(ind[r - 2], ind[r - 1]) > getIntersection(ind[r - 1], i))
    {
      r--;
    }
    ind[r] = i;
    r++;
  }
}

void WriteData()
{
  printf("%I64d\n", dp[n - 1]);
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