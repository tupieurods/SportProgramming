#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int testCnt, k;

void ReadData()
{
  scanf("%d %d", &testCnt, &k);
}

int dp[100009];
const int MOD = 1000000007;
int sums[100009];

void Solve()
{
  for(int i = 0; i < k; i++)
  {
    dp[i] = 1;
  }
  for(int i = k ; i < 100009; i++)
  {
    dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
  }
  sums[0] = 0;
  for(int i = 1; i < 100009; i++)
  {
    sums[i] = (dp[i] + sums[i - 1]) % MOD;
  }
  for(int i = 0; i < testCnt; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    int answer = sums[r] - sums[l - 1];
    if(answer < 0)
    {
      answer += MOD;
    }
    printf("%d\n", answer);
  }
}

void WriteData()
{
  printf("\n");
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