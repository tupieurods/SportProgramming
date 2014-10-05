#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MOD = 1000000007;

int n, h;
int a[2009];

void ReadData()
{
  scanf("%d %d", &n, &h);
  for(int i = 0; i < n; i++)
  {
    scanf("%d\n", &a[i]);
  }
}

int answer;
int dp[2009][2009];
int level;

int f(int idx, int opened)
{
  if(dp[idx][opened] != -1)
  {
    return dp[idx][opened];
  }
  dp[idx][opened] = 0;
  if(a[idx - 1] + opened == h)
  {
    if(opened > 0)
    {
      dp[idx][opened] = (dp[idx][opened] + f(idx - 1, opened - 1)) % MOD;
      if(dp[idx][opened] < 0)
      {
        dp[idx][opened] += MOD;
      }
    }

    dp[idx][opened] = (dp[idx][opened] + f(idx - 1, opened)) % MOD;
    if(dp[idx][opened] < 0)
    {
      dp[idx][opened] += MOD;
    }
  }
  else if(a[idx - 1] + opened + 1 == h)
  {
    dp[idx][opened] = (dp[idx][opened] + (f(idx - 1, opened + 1) * 1LL * (opened + 1LL)) % MOD) % MOD;
    if(dp[idx][opened] < 0)
    {
      dp[idx][opened] += MOD;
    }

    dp[idx][opened] = (dp[idx][opened] + f(idx - 1, opened)) % MOD;
    if(dp[idx][opened] < 0)
    {
      dp[idx][opened] += MOD;
    }

    if(opened > 0)
    {
      dp[idx][opened] = (dp[idx][opened] + (f(idx - 1, opened) * 1LL * opened) % MOD) % MOD;
      if(dp[idx][opened] < 0)
      {
        dp[idx][opened] += MOD;
      }
    }
  }
  return dp[idx][opened];
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  level = -1;
  dp[1][0] = (a[0] == h || a[0] + 1 == h ? 1 : 0);
  dp[1][1] = (a[0] + 1 == h ? 1 : 0);
  answer = f(n, 0);
}

void WriteData()
{
  printf("%d\n", answer);
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