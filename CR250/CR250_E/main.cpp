#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MOD = 1000000007;

struct point
{
  __int64 x, y;
};

int n;
point p[209];

__int64 crossMul(point p1, point p2)
{
  return p1.x * p2.y - p2.x * p1.y;
}

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d %I64d", &p[i].x, &p[i].y);
  }
  p[n] = p[0];
  __int64 areaVal = 0LL;
  for(int i = 0; i < n; i++)
  {
    areaVal += crossMul(p[i], p[i + 1]);
  }
  //printf("%I64d\n", areaVal);
  if(areaVal < 0)//Мы обходим многоугольник против часовой стрелки
  //а дано по часовой, изменим
  {
    std::reverse(p, p + n);
    p[n] = p[0];
    /*areaVal = 0LL;
    for(int i = 0; i < n; i++)
    {
      areaVal += crossMul(p[i], p[i + 1]);
    }
    printf("%I64d\n", areaVal);*/
  }
}

__int64 answer;
__int64 dp[209][209];

__int64 f(int l, int r)
{
  if(dp[l][r] != -1)
  {
    return dp[l][r];
  }
  if(l == r - 1)
  {
    dp[l][r] = 1;
    return 1;
  }
  point pMain;
  pMain.x = p[r].x - p[l].x;
  pMain.y = p[r].y - p[l].y;
  dp[l][r] = 0;
  for(int k = l + 1; k < r; k++)
  {
    point cp;
    cp.x = p[r].x - p[k].x;
    cp.y = p[r].y - p[k].y;
    if(crossMul(pMain, cp) > 0)
    {
      dp[l][r] = (dp[l][r] + f(l, k) * f(k, r)) % MOD;
    }
  }
  return dp[l][r];
}

void Solve()
{
  answer = 0;
  memset(dp, 0xFF, sizeof(dp));
  answer = f(0, n - 1);
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
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}