#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LOCAL
#include <inttypes.h>
#define __int64 int64_t
#endif

int n;
int a[500000], p[500000];
void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &p[i], &a[i]);
  }
}

__int64 dp[500000];
__int64 answer;

inline __int64 min(__int64 v1, __int64 v2)
{
  return v1 < v2 ? v1 : v2;
}

__int64 f(int solved)
{
  if(solved == n)
    return 0LL;
  if(dp[solved] != -1)
    return dp[solved];
  __int64 result = f(solved + 1);
  if(a[solved] < result)
    result = min(result + p[solved], result + 1);
  else
  {
    result = min(result + p[solved], result + (result - a[solved]) + 1);
  }
  dp[solved] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  answer = f(0);
}

void WriteData()
{
  printf("%lld\n", answer);
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