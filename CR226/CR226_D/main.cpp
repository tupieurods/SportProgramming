#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>

struct proj
{
  double x, y;
  int angle;
};

int n;
double l, r;
proj a[29];

void ReadData()
{
  scanf("%d %lf %lf", &n, &l, &r);
  r -= l;
  for(int i = 0; i < n; i++)
  {
    scanf("%lf %lf %d", &a[i].x, &a[i].y, &a[i].angle);
    a[i].x -= l;
  }
}

double answer;
double dp[(1 << 20) + 9];

/*
situation xxx
|
|         /
|        /
|       /
|      *
|       \
|________\|_________r________
*/

double calcRightMostX(double start, int idx)
{
  double angle = (a[idx].angle * M_PI) / 180.0;
  double dx = start - a[idx].x;
  double dy = -a[idx].y;
  dx = dx * cos(angle) - dy * sin(angle);
  dy = (start - a[idx].x) * sin(angle) + dy * cos(angle);
  if(fabs(dy) < 1e-9 || dy > 0)//Parallel to OX or situation xxx
  {
    return r;
  }
  dx /= dy;
  dy = 1.0;
  return a[idx].x - a[idx].y * dx;
}

void Solve()
{
  memset(dp, 0, sizeof(dp));
  answer = 0;
  int cnt = 1 << n;
  for(int mask = 0; mask < cnt; mask++)
  {
    for(int j = 0; j < n; j++)
    {
      if((mask & (1 << j)) != 0)
      {
        continue;
      }
      dp[mask | (1 << j)] = std::max(dp[mask | (1 << j)], calcRightMostX(dp[mask], j));
      answer = std::max(answer, dp[mask | (1 << j)]);
    }
  }
}

void WriteData()
{
  printf("%.10lf\n", std::min(answer, r));
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