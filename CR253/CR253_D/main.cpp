#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
double p[109];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%lf", &p[i]);
  }
}

double answer;
double dp[109], muls[109];
bool used[109];
int idx[109];

void Solve()
{
  answer = 0;
  memset(used, 0, sizeof(used));
  memset(dp, 0, sizeof(dp));
  memset(muls, 0, sizeof(muls));
  memset(idx, 0, sizeof(idx));
  p[0] = 0;
  for(int i = 1; i <= n; i++)
  {
    int idxBest = -1;
    for(int j = 1; j <= n; j++)
    {
      if(used[j])
      {
        continue;
      }
      double current = p[j];
      double sumc = 0;
      for(int k = 0; k < i; k++)
      {
        current *= 1.0 - p[idx[k]];
        sumc += muls[k] * (1.0 - p[j]);
      }
      sumc += current;
      if(sumc > dp[i])
      {
        dp[i] = sumc;
        idxBest = j;
      }
    }
    double current = p[idxBest];
    double sumc = 0;
    for(int k = 0; k < i; k++)
    {
      current *= 1.0 - p[idx[k]];
      muls[k] *= 1.0 - p[idxBest];
    }
    idx[i] = idxBest;
    used[idxBest] = true;
    muls[i] = current;
    answer = std::max(answer, dp[i]);
  }
}

void WriteData()
{
  printf("%.15lf\n", answer);
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