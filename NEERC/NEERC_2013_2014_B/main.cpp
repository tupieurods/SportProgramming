#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, a, b;

void ReadData()
{
  scanf("%d %d %d", &n, &a, &b);
}

double dp[3009][3009];
bool dpUse[3009][3009];

double f(int aVal, int bVal)
{
  __int64 used = a - aVal + b - bVal;
  if(used == n || aVal < 0 || bVal < 0)
  {
    return 0;
  }
  if(dpUse[a - aVal][b - bVal])
  {
    return dp[a - aVal][b - bVal];
  }
  double v = aVal * 2.0 + bVal + 2.0;
  v = 2.0 / v + ((aVal * 2.0) / v) * f(aVal - 1, bVal) + (bVal / v) * f(aVal, bVal - 1);
  dp[a - aVal][b - bVal] = v;
  dpUse[a - aVal][b - bVal] = true;
  return v;
}

double g(int aVal, int bVal)
{
  __int64 used = a - aVal + b - bVal;
  if(used == n || aVal < 0 || bVal < 0)
  {
    return 0;
  }
  if(dpUse[a - aVal][b - bVal])
  {
    return dp[a - aVal][b - bVal];
  }
  double v = aVal * 2.0 + bVal + 1.0;
  v = 1.0 / v + ((aVal * 2.0) / v) * g(aVal - 1, bVal) + (bVal / v) * g(aVal, bVal - 1);
  dp[a - aVal][b - bVal] = v;
  dpUse[a - aVal][b - bVal] = true;
  return v;
}

void Solve()
{
  memset(dpUse, 0, sizeof(dpUse));
  double answer = f(a, b);
  printf("%.10lf\n", answer);
  memset(dpUse, 0, sizeof(dpUse));
  answer = g(a, b);
  printf("%.10lf\n", answer);
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
  #else
  freopen("bonus.in", "r", stdin);
  freopen("bonus.out", "w", stdout);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}