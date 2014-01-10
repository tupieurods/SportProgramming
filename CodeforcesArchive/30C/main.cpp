#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct target
{
  int x, y;
  double p;
  __int64 t;
};

int n;
target targets[1000];

double dp[1000];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d %I64d %lf", &targets[i].x, &targets[i].y,
      &targets[i].t, &targets[i].p);
  }
}

inline double max(double v1, double v2)
{
  return (v2 - v1) > 1e-7 ? v2 : v1;
}

inline __int64 distance(int v1, int v2)
{
  return (__int64)((targets[v1].x - targets[v2].x) * (targets[v1].x - targets[v2].x)
  + (targets[v1].y - targets[v2].y) * (targets[v1].y - targets[v2].y));
}

inline __int64 timeDistance(int v1, int v2)
{
  return (targets[v1].t - targets[v2].t) * (targets[v1].t - targets[v2].t);
}

double f(int current)
{
  if(current == n)
   throw;
  if(dp[current] != -1.0)
    return dp[current];
  double result = 0.0;
  for(int index = current + 1; index < n; index++)
  {
    if(distance(current, index) <= timeDistance(current, index))
      result = max(result, f(index));
  }
  result += targets[current].p;
  dp[current] = result;
  return result;
}

int compare(const void *v1, const void *v2)
{
  target elem1 = *(target*)v1;
  target elem2 = *(target*)v2;
  return (int)elem1.t - (int)elem2.t;
}

double answer;

void Solve()
{
  qsort(targets, n, sizeof(target), compare);
  answer = 0;
  for(int i = 0; i < 1000; i++)
  {
    dp[i] = -1.0;
  }
  for(int i = 0; i < n; i++)
  {
    answer = max(answer, f(i));
  }
}

void WriteData()
{
  printf("%.10lf\n", answer);
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