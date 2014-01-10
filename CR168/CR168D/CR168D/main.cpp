#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

#define LOCALTEST

struct vertex
{
  __int64 w;
  __int64 delta;
  deque<int> edgesTo;
};

struct layer
{
  __int64 min, max;
};

deque<pair<int, int>>* layers;
vertex* verticies;
int n;

int bfs()
{
  queue<int> Q;
  Q.push(1);
  int* visited = new int[n + 1];
  memset(visited, 0xFF, sizeof(int) * (n + 1));
  visited[1] = 0;
  int result = 0;

  while(!Q.empty())
  {
    int current = Q.front();
    Q.pop();
    for(int i = 0; i < verticies[current].edgesTo.size(); i++)
    {
      int to = verticies[current].edgesTo[i];
      if(visited[to] == -1)
      {
        Q.push(to);
        visited[to] = visited[current] + 1;
        result = max(result, visited[to]);
        layers[visited[to]].push_back(make_pair(current, to));
      }
    }
  }
  return result;
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
      verticies[i].delta = 0LL;
    }
    int layersCount = bfs();
    __int64 delta = 0;
    __int64 answer = 0;
    for(int i = layersCount; i > 0; i--)
    {
      int len = layers[i].size();
      __int64 minDelta = _I64_MAX;
      __int64 maxDelta = _I64_MIN;
      for(int j = 0; j < len; j++)
      {
        verticies[layers[i][j].second].w += verticies[layers[i][j].second].delta;
        printf("%I64d ", verticies[layers[i][j].second].w);
        __int64 tryToChangeDelta = (-verticies[layers[i][j].second].w + verticies[layers[i][j].second].delta);
        minDelta = min(minDelta, -verticies[layers[i][j].second].w);
        maxDelta = max(maxDelta, -verticies[layers[i][j].second].w);
        if(verticies[layers[i][j].first].delta != 0)
        {
          if((verticies[layers[i][j].first].delta >=0 && tryToChangeDelta >= 0)
           || (verticies[layers[i][j].first].delta <=0 && tryToChangeDelta <= 0))//Одного знака
          {
            if(_abs64(tryToChangeDelta) < _abs64(verticies[layers[i][j].first].delta))
              tryToChangeDelta = verticies[layers[i][j].first].delta;
          }
          else//Разных знаков
          {
            tryToChangeDelta += verticies[layers[i][j].first].delta;
          }
        }
        //printf("newdelta: %I64d for %d\n", tryToChangeDelta, layers[i][j].first);
        verticies[layers[i][j].first].delta = tryToChangeDelta;
      }
      printf("\n");
      //printf("min: %I64d max: %I64d\n", minDelta, maxDelta);
      if((minDelta <= 0 && maxDelta <= 0) || (minDelta >= 0 && maxDelta >= 0))
      {
        answer += max(_abs64(minDelta), _abs64(maxDelta));
      }
      else
      {
         answer += _abs64(minDelta) + _abs64(maxDelta);
      }
    }
    answer += _abs64(verticies[1].delta + verticies[1].w);
    printf("%I64d\n", answer);
    printf("%I64d\n", verticies[1].delta);
  }
  return 0;
}