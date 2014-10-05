#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int cnt[100009];

void ReadData()
{
  scanf("%d", &n);
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    cnt[val]++;
  }
}

__int64 dp[100009];

void Solve()
{
  dp[0] = 0;
  dp[1] = cnt[1];
  for(int i = 2; i < 100001; i++)
  {
    dp[i] = std::max(dp[i - 1], dp[i - 2] + cnt[i] * 1LL * i);
  }
}

void WriteData()
{
  printf("%I64d\n", dp[100000]);
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