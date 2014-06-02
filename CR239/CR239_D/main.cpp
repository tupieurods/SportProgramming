#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma comment(linker, "/STACK:36777216")

int n;
int p[1009];
const int MOD = 1000000007;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &p[i]);
  }
}

int answer;
int dp[1009];

void Solve()
{
  memset(dp, 0, sizeof(dp));
  for(int i = 2; i <= n + 1; i++)
  {
    //lets Q = i - 1. In this case, if we in cell i, we did steps:
    //1->Q. Thats dp[i - 1]
    //We moved to p[Q]. Thats 1
    //We moved from p[Q] to Q again. Thats dp[i - 1] - dp[p[i - 1]]
    //Finially, we moved to i. Thats 1
    dp[i] = (((2 * dp[i - 1] + 2) % MOD) - dp[p[i - 1]] + MOD) % MOD;
  }
  answer = dp[n + 1];
}

void WriteData()
{
  printf("%d\n", answer);
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