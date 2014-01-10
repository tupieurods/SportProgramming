#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> verticies[109];

void ReadData()
{
  scanf("%d %d", &n, &m);
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 100; i++)
  {
    verticies[i].clear();
  }
  #endif
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    verticies[from].push_back(to);
    verticies[to].push_back(from);
  }
}

__int64 ways;
__int64 answer;
__int64 d[109], dp[109], dp2[109];

void bfs()
{
  memset(d, 0xFF, sizeof(d));
  queue<int> q;
  d[0] = 0;
  q.push(0);

  while(!q.empty())
  {
    int current = q.front();
    q.pop();

    for(int i = 0; i < verticies[current].size(); i++)
    {
      if(d[verticies[current][i]] == -1)
      {
        d[verticies[current][i]] = d[current] + 1;
        q.push(verticies[current][i]);
      }
    }
  }
}

__int64 f(int vertex)
{
  if(vertex == n - 1)
    return 1;
  if(dp[vertex] != -1)
    return dp[vertex];
  __int64 result = 0;
  for(int i = 0; i < verticies[vertex].size(); i++)
  {
    if(d[verticies[vertex][i]] == d[vertex] + 1)
    {
      result += f(verticies[vertex][i]);
    }
  }
  dp[vertex] = result;
  return result;
}

__int64 f2(int vertex)
{
  if(vertex == 0)
    return 1;
  if(dp2[vertex] != -1)
    return dp2[vertex];
  __int64 result = 0;
  for(int i = 0; i < verticies[vertex].size(); i++)
  {
    if(d[verticies[vertex][i]] == d[vertex] - 1)
    {
      result += f2(verticies[vertex][i]);
    }
  }
  dp2[vertex] = result;
  return result;
}

void Solve()
{
  ways = 0;
  answer = 0;
  bfs();
  memset(dp, 0xFF, sizeof(dp));
  memset(dp2, 0xFF, sizeof(dp2));
  ways = f(0);
  f2(n - 1);
  answer = ways;
  for(int i = 1; i < n - 1; i++)
  {
    answer = max(answer, dp[i] * dp2[i] * 2LL);
  }
}

void WriteData()
{
  if(ways == 0)
  {
    throw;
  }
  printf("%.10lf\n", (double)answer / (double) ways);
  //printf("%.10lf\n", (double) ways);
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