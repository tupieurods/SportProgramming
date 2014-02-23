#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k;
__int64 c[100009];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &c[i]);
  }
}

int answer;

int dp[100009];

int f(int current)
{
  if(dp[current] != -1)
  {
    return dp[current];
  }
  int result = current;
  for(int i = 1; i <= k; i++)
  {
    if(current + i >= n)
    {
      break;
    }
    if(c[current + i] > c[current])
    {
      result = std::max(result, f(current + i));
    }
  }
  dp[current] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  dp[n - 1] = n - 1;
  answer = 0;
  for(int i = 0; i < k; i++)
  {
    answer = std::max(answer, f(i));
  }
}

void WriteData()
{
  printf("%d\n", answer + 1);
}

int main()
{
  int QWE = 1;
  freopen("LADDER.IN", "r", stdin);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}