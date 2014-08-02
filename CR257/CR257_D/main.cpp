#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct edge
{
  int from, to;
  __int64 val;
};

int n, m, k, rIdx;
vector<edge> edges;
vector<int> edgesId[100009];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  edges.clear();
  for(int i = 0; i < 100009; i++)
  {
    edgesId[i].clear();
  }
  #endif
  scanf("%d %d %d", &n, &m, &k);
  int id = 0;
  for(int i = 0; i < m; i++)
  {
    edge edg, edg2;
    scanf("%d %d %I64d", &edg.from, &edg.to, &edg.val);
    edg.from--;
    edg.to--;
    edges.push_back(edg);
    edgesId[edg.from].push_back(id++);
    edg2.to = edg.from;
    edg2.from = edg.to;
    edg2.val = edg.val;
    edges.push_back(edg2);
    edgesId[edg2.from].push_back(id++);
  }
  rIdx = edges.size();
  for(int i = 0; i < k; i++)
  {
    edge edg, edg2;
    scanf("%d %I64d", &edg.to, &edg.val);
    edg.from = 0;
    edg.to--;
    edges.push_back(edg);
    edgesId[edg.from].push_back(id++);
    edg2.to = edg.from;
    edg2.from = edg.to;
    edg2.val = edg.val;
    edges.push_back(edg2);
    edgesId[edg2.from].push_back(id++);
  }
}

int answer;
__int64 dist[100009];
int inCnt[100009];

void Solve()
{
  answer = 0;
  set<pair<__int64, int>> s;
  s.insert(make_pair(0, 0));
  dist[0] = 0;
  for(int i = 1; i < n; i++)
  {
    s.insert(make_pair(_I64_MAX, i));
    dist[i] = _I64_MAX;
  }
  while(!s.empty())
  {
    pair<__int64, int> current = *s.begin();
    s.erase(s.begin());
    for(vector<int>::iterator it = edgesId[current.second].begin(); it != edgesId[current.second].end(); it++)
    {
      if(dist[current.second] + edges[*it].val < dist[edges[*it].to])
      {
        s.erase(make_pair(dist[edges[*it].to], edges[*it].to));
        dist[edges[*it].to] = dist[current.second] + edges[*it].val;
        s.insert(make_pair(dist[edges[*it].to], edges[*it].to));
      }
    }
  }
  //printf("stage1\n");
  memset(inCnt, 0, sizeof(inCnt));
  for(int i = 0; i < rIdx; i++)
  {
    if(dist[edges[i].from] + edges[i].val == dist[edges[i].to])
    {
      inCnt[edges[i].to]++;
    }
  }
  int cnt = edges.size();
  for(int i = rIdx; i < cnt; i += 2)
  {
    if(dist[edges[i].from] + edges[i].val == dist[edges[i].to])
    {
      if(inCnt[edges[i].to] != 0)
      {
        answer++;
      }
      else
      {
        inCnt[edges[i].to]++;
      }
    }
    else
    {
      answer++;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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