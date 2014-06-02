#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool answer;
int g[100009][4];

void ReadData()
{
  answer = true;
  scanf("%d", &n);
  memset(g, 0xFF, sizeof(g));
  for(int i = 0; i < 100009; i++)
  {
    g[i][3] = 0;
  }
  for(int i = 1; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    if(g[from][3] == 3)
    {
      answer = false;
    }
    else
    {
      g[from][g[from][3]] = to;
      g[from][3]++;
    }
    if(g[to][3] == 3)
    {
      answer = false;
    }
    else
    {
      g[to][g[to][3]] = from;
      g[to][3]++;
    }
  }
}

int getIdx(int v, int parent)
{
  for(int i = 0; i < 3; i++)
  {
    if(g[v][i] == parent)
    {
      return i + 1;
    }
  }
  return 0;
}

int ans;
int dp[100009][4];

int f(int v, int parent)
{
  int idx = getIdx(v, parent);
  if(dp[v][idx] != -1)
  {
    return dp[v][idx];
  }
  /*if(v == 1 && idx == 1)
  {
    printf("wat\n");
  } */
  int result = 0;
  int checker = idx == 0 ? g[v][3] : g[v][3] - 1;
  switch(checker)
  {
  case 1:
    {
      result = 2;
      break;
    }
  case 2:
    {
      result = 1;
      break;
    }
  case 3:
    {
      result = 3;
      break;
    }
  default:
    {
      break;
    }
  }
  for(int i = 0; i < g[v][3]; i++)
  {
    if(g[v][i] != parent)
    {
      result += f(g[v][i], v);
    }
  }
  dp[v][idx] = result;
  return result;
}

void Solve()
{
  if(answer == false)
  {
    ans = -1;
    return;
  }
  ans = INT_MAX;
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 1; i <= n; i++)
  {
    ans = min(ans, f(i, 0));
    //printf("%d\n", ans);
  }
}

void WriteData()
{
  printf("%d\n", ans);
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