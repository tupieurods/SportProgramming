#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n;
int a[100009], dp[100009];
const int INF = 10000000;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;

void Solve()
{
  dp[0] = -INF;
  for(int i = 1; i < 100009; i++)
  {
    dp[i] = INF;
  }
  for(int i = 0; i < n; i++)
  {
    int j = (int)(std::upper_bound(dp, dp + 100009, a[i]) - dp);
    if(dp[j - 1] < a[i] && a[i] < dp[j])
    {
      dp[j] = a[i];
    }
  }
  answer = -1;
  for(int i = 100000; i > 0; i--)
  {
    if(dp[i] != INF)
    {
      answer = i;
      return;
    }
  }
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