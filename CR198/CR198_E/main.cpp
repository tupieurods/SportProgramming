#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
bool used[2009];
int a[2009];
const int MOD = 1000000007;
int p;
__int64 fact[2009];

void ReadData()
{
  scanf("%d", &n);
  memset(used, 0, sizeof(used));
  p = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    if(a[i] != -1)
    {
      used[a[i] - 1] = true;
    }
    else
    {
      p++;
    }
  }
}

__int64 dp[2009][2009];

__int64 f(int nCnt, int kCnt)
{
  if(dp[nCnt][kCnt] != -1)
  {
    return dp[nCnt][kCnt];
  }
  if(kCnt > 1)
  {
    __int64 result = (nCnt - 1) * f(nCnt - 1, kCnt - 1) % MOD;
    dp[nCnt][kCnt] = (result + (kCnt - 1) * f(nCnt - 2, kCnt - 2)) % MOD;
    return dp[nCnt][kCnt];
  }
  if(kCnt == 1)
  {
    return (fact[nCnt - 1] * (nCnt - 1))% MOD;
  }
  if(kCnt == 0)
  {
    return fact[nCnt];
  }
  throw;
}

__int64 answer;

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  int k = 0;
  for(int i = 0; i < n; i++)
  {
    if(!used[i] && a[i] == -1)
    {
      k++;
    }
  }
  answer = f(p, k) % MOD;
  if(answer < 0)
  {
    answer += MOD;
  }
  answer %= MOD;
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
  fact[0] = 1;
  fact[1] = 1;
  for(int i = 2; i < 2001; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}