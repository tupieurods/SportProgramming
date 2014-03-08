#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

#pragma warning(disable: 4996)

#define MAXN 309
#define INF 1LL << 60

int n, m, k;
__int64 cost[MAXN][MAXN];
__int64 dp[MAXN][MAXN];

void ReadData()
{
  for(int i = 0; i < MAXN; i++)
  {
    for(int j = 0; j < MAXN; j++)
    {
      cost[i][j] = INF;
    }
  }
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < m; i++)
  {
    int l, r, c;
    scanf("%d %d %d", &l, &r, &c);
    for(int j = l; j <= r; j++)
    {
      cost[l][j] = min(cost[l][j], (__int64)c);
    }
  }
}

__int64 f(int last, int toFill)
{
  if(last < toFill)
  {
    return INF;
  }
  if(toFill == 0)
  {
    return 0LL;
  }
  if(dp[last][toFill] != -1)
  {
    return dp[last][toFill];
  }
  __int64 result = min(INF, f(last - 1, toFill));
  for(int i = 1; i <= toFill; i++)
  {
    __int64 current = f(last - i, toFill - i);
    if(current != INF)
    {
      result = min(result, current + cost[last - i + 1][last]);
    }
  }
  dp[last][toFill] = result;
  return result;
}

__int64 answer;

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  answer = f(n, k);
}

void WriteData()
{
  printf("%I64d\n", answer == INF ? -1 : answer);
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