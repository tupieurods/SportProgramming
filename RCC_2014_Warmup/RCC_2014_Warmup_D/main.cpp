#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct buddy
{
  int x, k, m;
};

int n, m, b;
map<int, vector<int>> monitors;
int canSolve[109][29];
buddy fr[109];

void ReadData()
{
  scanf("%d %d %d", &n, &m, &b);
  monitors.clear();
  for(int i = 0; i < n; i++)
  {
    int cnt;
    scanf("%d %d %d", &fr[i].x, &fr[i].k, &cnt);
    fr[i].m = 0;
    for(int j = 0; j < cnt; j++)
    {
      int val;
      scanf("%d", &val);
      //scanf("%d", &canSolve[i][j]);
      fr[i].m |= 1 << (val - 1);
    }
  }
}

__int64 answer;

int comparer(const void *v1, const void *v2)
{
  buddy *v1_p = (buddy*)v1;
  buddy *v2_p = (buddy*)v2;
  return v1_p->k - v2_p->k;
}

__int64 dp[(1 << 20) + 9];

void Solve()
{
  qsort(fr, n, sizeof(buddy), comparer);
  for(int i = 0; i < (1 << 20) + 9; i++)
  {
    dp[i] = _I64_MAX;
  }
  answer = _I64_MAX;
  dp[0] = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < (1 << m); j++)
    {
      if(dp[j] != _I64_MAX)
      {
        int current = j | fr[i].m;
        dp[current] = std::min(dp[current], dp[j] + fr[i].x);
      }
    }
    if(dp[(1 << m) - 1] != _I64_MAX)
    {
      answer = std::min(answer, dp[(1 << m) - 1] + b * 1LL * fr[i].k);
    }
  }
}

void WriteData()
{
  if(answer == _I64_MAX)
  {
    printf("-1\n");
  }
  else
  {
    printf("%I64d\n", answer);
  }
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