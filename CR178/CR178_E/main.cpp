#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, __int64>> g[5009];

void ReadData()
{
#ifndef ONLINE_JUDGE
  for(int i = 0; i < 5009; i++)
  {
    g[i].clear();
  }
#endif
  scanf("%d", &n);
  for(int i = 1; i < n; i++)
  {
    int from, to, w;
    scanf("%d %d %d", &from, &to, &w);
    from--;
    to--;
    g[from].push_back(make_pair(to, w));
    g[to].push_back(make_pair(from, w));
  }
}

__int64 answer;
__int64 totalDist, bestSubtreeDist, extra, subtreeCnt;
int treeSize[5009];

__int64 dfs(int current, int parent, __int64 dist)
{
  subtreeCnt++;
  treeSize[current] = 1;
  __int64 result = dist;
  for(vector<pair<int, __int64>>::iterator it = g[current].begin(); it != g[current].end(); it++)
  {
    if(it->first == parent)
    {
      continue;
    }
    result += dfs(it->first, current, dist + it->second);
    treeSize[current] += treeSize[it->first];
  }
  return result;
}

void findNodeWithMinDist(int current, int parent, __int64 dist)
{
  bestSubtreeDist = min(bestSubtreeDist, dist);
  totalDist += dist;
  for(vector<pair<int, __int64>>::iterator it = g[current].begin(); it != g[current].end(); it++)
  {
    if(it->first == parent)
    {
      continue;
    }
    //previously we calculated dist from parent to other verticies in subtree
    //now we should recalc it to dist from it->first to other
    //So: we should remove treeSize[it->first] steps
    //and add n - treeSize[it->first] steps through edge
    findNodeWithMinDist(it->first, current, dist + it->second * (subtreeCnt - 2 * treeSize[it->first]));
  }
}

void ProcessSubtree(int current, int parent)
{
  subtreeCnt = 0;
  bestSubtreeDist = dfs(current, parent, 0);
  findNodeWithMinDist(current, parent, bestSubtreeDist);
  extra += bestSubtreeDist * (n - subtreeCnt);
}

void Solve()
{
  answer = _I64_MAX;
  for(int from = 0; from < n; from++)
  {
    for(vector<pair<int, __int64>>::iterator it = g[from].begin(); it != g[from].end(); it++)
    {
      if(from > it->first)
      {
        continue;
      }
      totalDist = 0;
      bestSubtreeDist = 0;
      extra = 0;
      ProcessSubtree(from, it->first);
      ProcessSubtree(it->first, from);
      extra += it->second * subtreeCnt * (n - subtreeCnt);
      answer = min(answer, totalDist / 2 + extra);
      // totalDist / 2, because we calculated distance from a to b and from b to a. Twice in other words
    }
  }
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