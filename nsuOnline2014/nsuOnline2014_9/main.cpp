#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const __int64 INF = 1e13;

struct edge
{
  int to, len;
  __int64 ltoDark;
  int endHeat;

  edge(int _to, int _len, int _ltoDark): to(_to), len(_len), ltoDark(_ltoDark)
  {
    this->endHeat = 0;
  }
};

int N, M, T, A, B;
vector<edge> edges[10009];
int edgesL[10009];
int blackDist[109];

bool blackV2[210000];
vector<pair<int, int>> edgesV2[210000];
int cntV2;

void ReadData()
{
  memset(blackV2, false, sizeof(blackV2));
  scanf("%d %d %d %d %d", &N, &M, &T, &A, &B);
  A--, B--;
  cntV2 = N;
  for(int i = 0; i < M; i++)
  {
    int from, to, k, prevLight = 0;
    scanf("%d %d", &from, &to);
    from--, to--;
    scanf("%d", &k);
    bool useable = true;
    edge toEdge(to, 0, -1);
    edge fromEdge(from, 0, 0);
    for(int j = 0; j < k; j++)
    {
      int ll, tt;
      scanf("%d %d", &ll, &tt);
      toEdge.len += ll;
      fromEdge.len += ll;
      if(tt == 1)
      {
        prevLight += ll;
        useable = useable && (prevLight <= T);
      }
      else
      {
        if(toEdge.ltoDark == -1)
        {
          toEdge.ltoDark = prevLight;
        }
        prevLight = 0;
      }
      if(j == 0 || j == k - 1)
      {
        if(j == 0)
        {
          if(tt == 0)
          {
            blackV2[from] = true;
            blackV2[cntV2] = true;
          }
          edgesV2[from].push_back(make_pair(cntV2, ll));
          edgesV2[cntV2].push_back(make_pair(from, ll));
          cntV2++;
        }
        if(j == k - 1)
        {
          if(tt == 0)
          {
            blackV2[to] = true;
            blackV2[cntV2] = true;
          }
          fromEdge.ltoDark = prevLight;
          edgesV2[to].push_back(make_pair(cntV2 - 1, ll));
          edgesV2[cntV2 - 1].push_back(make_pair(to, ll));
        }
      }
      else
      {
        if(tt == 0)
        {
          blackV2[cntV2 - 1] = true;
          blackV2[cntV2] = true;
        }
        edgesV2[cntV2 - 1].push_back(make_pair(cntV2, ll));
        edgesV2[cntV2].push_back(make_pair(cntV2 - 1, ll));
        cntV2++;
      }
    }
    if(useable)
    {
      if(toEdge.ltoDark != -1)
      {
        toEdge.endHeat = fromEdge.ltoDark;
        fromEdge.endHeat = toEdge.ltoDark;
      }
      else
      {
        toEdge.ltoDark = fromEdge.ltoDark = INF;
        toEdge.endHeat = fromEdge.endHeat = prevLight;
      }
      edges[from].push_back(toEdge);
      edges[to].push_back(fromEdge);
    }
  }
}

__int64 answer;
int distV2[210000];
__int64 ddist[109][159];

void Solve()
{
  answer = _I64_MAX;
  set<pair<int, int>> s;
  set<pair<int, int>>::iterator itS;
  for(int v2VertexID = 0; v2VertexID < N; v2VertexID++)
  {
    s.clear();
    s.insert(make_pair(0, v2VertexID));
    memset(distV2, 0x7F, sizeof(distV2));
    distV2[v2VertexID] = 0;
    blackDist[v2VertexID] = T + 9;

    while(!s.empty())
    {
      pair<int, int> currentV = *s.begin();
      s.erase(s.begin());

      if(currentV.first > T)
      {
        break;
      }

      if(blackV2[currentV.second])
      {
        blackDist[v2VertexID] = currentV.first;
        break;
      }

      for(vector<pair<int, int>>::iterator it = edgesV2[currentV.second].begin(); it != edgesV2[currentV.second].end(); ++it)
      {
        if(distV2[currentV.second] + it->second < distV2[it->first])
        {
          itS = s.find(make_pair(distV2[it->first], it->first));
          if(itS != s.end())
          {
            s.erase(itS);
          }
          distV2[it->first] = distV2[currentV.second] + it->second;
          s.insert(make_pair(distV2[it->first], it->first));
        }
      }
    }
  }
  //printf("phase 1 done!\n");
  set<pair<__int64, int>> s2;
  set<pair<__int64, int>>::iterator itS2;
  s2.insert(make_pair(0, A * 1000 + 0));
  for(int i = 0; i < 109; i++)
  {
    for(int j = 0; j < 159; j++)
    {
      ddist[i][j] = _I64_MAX;
    }
  }
  ddist[A][0] = 0;
  while(!s2.empty())
  {
    pair<__int64, int> currentS = *s2.begin();
    s2.erase(s2.begin());
    int currentV = currentS.second / 1000;
    int currentHeat = currentS.second % 1000;

    for(vector<edge>::iterator it = edges[currentV].begin(); it != edges[currentV].end(); ++it)
    {
      if(currentHeat + (it->ltoDark == INF ? it->len : it->ltoDark) <= T)
      {
        int resHeat = (it->ltoDark == INF ? currentHeat + it->len : it->endHeat);
        __int64 newL = ddist[currentV][currentHeat] + it->len;
        if(newL < ddist[it->to][resHeat])
        {
          itS2 = s2.find(make_pair(ddist[it->to][resHeat], it->to * 1000 + resHeat));
          if(itS2 != s2.end())
          {
            s2.erase(itS2);
          }
          ddist[it->to][resHeat] = newL;
          s2.insert(make_pair(newL, it->to * 1000 + resHeat));
        }
      }

      if(blackDist[currentV] + currentHeat <= T//Можем добежать до тени
        && blackDist[currentV] < currentHeat//После возвращения из тени будет меньше времени на солнце
        //И если есть смысл бежать
        && ddist[currentV][currentHeat] + blackDist[currentV] * 2 < ddist[currentV][blackDist[currentV]])
      {
        //printf("!");
        itS2 = s2.find(make_pair(ddist[currentV][blackDist[currentV]], currentV * 1000 + blackDist[currentV]));
        if(itS2 != s2.end())
        {
          s2.erase(itS2);
        }
        ddist[currentV][blackDist[currentV]] = ddist[currentV][currentHeat] + blackDist[currentV] * 2;
        s2.insert(make_pair(ddist[currentV][currentHeat] + blackDist[currentV] * 2, currentV * 1000 + blackDist[currentV]));
      }
    }
  }
  for(int i = 0; i < 159; i++)
  {
    answer = min(answer, ddist[B][i]);
  }
}

void WriteData()
{
  printf("%I64d\n", answer == _I64_MAX ? -1 : answer);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  WriteData();
  return 0;
}