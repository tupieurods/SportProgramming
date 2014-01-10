#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

//#define LOCALTEST

struct vertex
{
  __int64 w;
  __int64 decCount;
  __int64 incCount;
  bool visited;
  deque<int> edgesTo;
};

struct layer
{
  __int64 min, max;
};

void dfsVisit(int index);

deque<pair<int, int>>* layers;
vertex* verticies;
int n;

void dfs()
{
  /*for(int i = 1; i <= n; i++)
  {
  if(!verticies[i].visited)
  {*/
  dfsVisit(1);
  /*}
  }*/
}

void dfsVisit(int index)
{
  int len = verticies[index].edgesTo.size();
  __int64 maxDec = 0LL;
  __int64 maxInc = 0LL;
  verticies[index].visited = true;
  for(int i = 0; i < len; i++)
  {
    if(!verticies[verticies[index].edgesTo[i]].visited)
    {
      dfsVisit(verticies[index].edgesTo[i]);
      maxDec = max(maxDec, verticies[verticies[index].edgesTo[i]].decCount);
      maxInc = max(maxInc, verticies[verticies[index].edgesTo[i]].incCount);
    }
  }
  verticies[index].w += -maxDec + maxInc;
  if(verticies[index].w != 0)
  {
    if(verticies[index].w > 0)
    {
      maxDec += verticies[index].w;
    }
    else
    {
      maxInc += -verticies[index].w;
    }
  }
  verticies[index].decCount = maxDec;
  verticies[index].incCount = maxInc;
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d", &n);
    verticies = new vertex[n + 1];
    layers = new deque<pair<int, int>>[n + 1];
    for(int i = 1; i < n; i++)
    {
      int from, to;
      scanf("%d %d", &from, &to);
      verticies[from].edgesTo.push_back(to);
      verticies[to].edgesTo.push_back(from);
    }
    for(int i = 1; i <= n; i++)
    {
      scanf("%I64d", &verticies[i].w);
      verticies[i].decCount = 0LL;
      verticies[i].incCount = 0LL;
      verticies[i].visited = false;
    }
    dfs();
    printf("%I64d\n", verticies[1].decCount + verticies[1].incCount);
  }
  return 0;
}