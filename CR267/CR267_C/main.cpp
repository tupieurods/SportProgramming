#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m, k;
int p[5009];
__int64 sums[5009];

__int64 getSum(int l, int r)
{
  return sums[r + 1] - sums[l];
}

void ReadData()
{
  memset(sums, 0, sizeof(sums));
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &p[i]);
    sums[i + 1] = sums[i] + p[i];
  }
}

__int64 answer;
__int64 dp[5009][5009];

__int64 f(int r, int steps)
{
  if(steps * m > r + 1 || steps <= 0)
  {
    return 0;
  }
  if(dp[r][steps] != -1)
  {
    return dp[r][steps];
  }
  if(steps * m == r + 1)
  {
    dp[r][steps] = getSum(0, r);
  }
  else
  {
    dp[r][steps] = std::max(f(r - 1, steps), f(r - m, steps - 1) + getSum(r - m + 1, r));
  }
  return dp[r][steps];
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  answer = f(n, k);
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n");
    printf("5000 1 4500\n");
    for(int i = 0; i < 5000; i++)
    {
      printf("1 ");
    }
    return 0;
  }
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
/*
2
5 2 1
1 2 3 4 5
7 1 3
2 10 7 18 5 33 0
*/