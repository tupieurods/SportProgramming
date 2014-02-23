#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

#pragma warning(disable: 4996)

struct edge
{
  int from, to, capacity, flow;
  edge* reverse;

  int resudial()
  {
    return capacity - flow;
  }
};

int n, m;
vector<pair<int, int>> inputEdges;
vector<edge*> edges;
vector<int> verticies[1009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  inputEdges.clear();
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    inputEdges.push_back(make_pair(from, to));
  }
}

void AddEdge(int from, int to, int capacity)
{
  edge* toAdd = new edge;
  toAdd->from = from;
  toAdd->to = to;
  toAdd->capacity = capacity;
  toAdd->flow = 0;

  edge* reverseEdge = new edge;
  reverseEdge->from = to;
  reverseEdge->to = from;
  reverseEdge->capacity = 0;
  reverseEdge->flow = 0;

  toAdd->reverse = reverseEdge;
  reverseEdge->reverse = toAdd;
  edges.push_back(toAdd);
  edges.push_back(reverseEdge);
  verticies[from].push_back(edges.size() - 2);
  verticies[to].push_back(edges.size() - 1);
}

int BuildGraph(int centralVertex)
{
  //Прибрались за предыдущим состоянием
  for(vector<edge*>::iterator it = edges.begin(); it != edges.end(); it++)
  {
    delete *it;
  }
  edges.clear();
  for(int i = 0; i < 1009; i++)
  {
    verticies[i].clear();
  }
  //Из истока
  for(int i = 1; i <= n; i++)
  {
    AddEdge(0, i, 1);
  }
  int result = 0;
  //Рёбра сети
  for(int i = 0; i < m; i++)
  {
    if(inputEdges[i].first == centralVertex || inputEdges[i].second == centralVertex)
    {
      result++;
      continue;
    }
    AddEdge(inputEdges[i].first, inputEdges[i].second + 500, 1);
  }
  //В сток
  for(int i = 1; i <= n; i++)
  {
    AddEdge(500 + i, 1005, 1);
  }
  return result;
}

int color[1009];
int currentDfsRun;
vector<int> way;

bool dfsVisit(int edgeInd);

bool dfs()
{
  currentDfsRun++;
  color[0] = currentDfsRun;
  way.clear();

  for(vector<int>::iterator it = verticies[0].begin(); it != verticies[0].end(); it++)
  {
    if(color[edges[*it]->to] != currentDfsRun && edges[*it]->resudial() > 0)
    {
      if(dfsVisit(*it))
      {
        return true;
      }
    }
  }
  return false;
}

bool dfsVisit(int edgeInd)
{
  way.push_back(edgeInd);
  color[edges[edgeInd]->to] = currentDfsRun;
  if(edges[edgeInd]->to == 1005)
  {
    return true;
  }
  for(vector<int>::iterator it = verticies[edges[edgeInd]->to].begin(); it != verticies[edges[edgeInd]->to].end(); it++)
  {
    if(color[edges[*it]->to] != currentDfsRun && edges[*it]->resudial() > 0)
    {
      if(dfsVisit(*it))
      {
        return true;
      }
    }
  }
  way.pop_back();
  return false;
}

int getMaxFlow()
{
  while(dfs())
  {
    int minimal = INT_MAX;
    for(vector<int>::iterator it = way.begin(); it != way.end(); it++)
    {
      minimal = min(minimal, edges[*it]->resudial());
    }
    for(vector<int>::iterator it = way.begin(); it != way.end(); it++)
    {
      edge* current = edges[*it];
      current->flow += minimal;
      current->reverse->flow -= minimal;
    }
  }
  int result = 0;
  for(vector<edge*>::iterator it = edges.begin(); it != edges.end(); it++)
  {
    if((*it)->from == 0)
    {
      result += (*it)->flow;
    }
  }
  return result;
}

int answer;

void Solve()
{
  memset(color, 0, sizeof(color));
  currentDfsRun = 0;
  answer = INT_MAX;
  for(int i = 1; i <= n; i++)
  {
    int cntWithI = BuildGraph(i);
    int other = m - cntWithI;
    int pMax = getMaxFlow();
    answer = min(answer, 3 * n - 2 + other - 2 * pMax - cntWithI);
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
    //time_t tm = clock();
    ReadData();
    Solve();
    WriteData();
    //printf("%.10f\n", (float)(clock() - tm)/CLOCKS_PER_SEC);
  }
  return 0;
}