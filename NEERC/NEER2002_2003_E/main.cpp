#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
  int x, y, cnt;
};

struct edge
{
  int from, to;
  int capacity, flow, cost;
  edge* reverse;

  int Resudial()
  {
    return capacity - flow;
  }
};

int R(const edge &edg)
{
  return edg.capacity - edg.flow;
}

int n, m;
info bs[209];
int matrix[109][109];
int sums[109];
int graph[209][209];
vector<edge*> edges;
const int MAX_VALUE = 1e7;
const __int64 INF = 1LL << 31;

void ReadData()
{
  scanf("%d %d", &n, &m);
  memset(sums, 0, sizeof(sums));
  for(int i = 0; i < n + m; i++)
  {
    scanf("%d %d %d", &bs[i].x, &bs[i].y, &bs[i].cnt);
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &matrix[i][j]);
      sums[j] += matrix[i][j];
    }
  }
}

int getCost(int id1, int id2)
{
  return 1 + abs(bs[id1].x - bs[id2].x) + abs(bs[id1].y - bs[id2].y);
}

void AddEdge(int from, int to, int capacity, int flow, int cost)
{
  edge* toAdd1 = new edge;
  toAdd1->from = from;
  toAdd1->to = to;
  toAdd1->capacity = capacity;
  toAdd1->flow = flow;
  toAdd1->cost = cost;

  edge* toAdd2 = new edge;
  toAdd2->from = to;
  toAdd2->to = from;
  toAdd2->capacity = 0;
  toAdd2->flow = -flow;
  toAdd2->cost = -cost;

  toAdd1->reverse = toAdd2;
  toAdd2->reverse = toAdd1;
  graph[from][to] = edges.size();
  edges.push_back(toAdd1);
  graph[to][from] = edges.size();
  edges.push_back(toAdd2);
}

void BuildGraph()
{
  memset(graph, 0xFF, sizeof(graph));
  edges.clear();
  for(int i = 0; i < n; i++)
  {
    AddEdge(0, i + 1, bs[i].cnt, bs[i].cnt, 0);
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      AddEdge(i + 1, n + j + 1, MAX_VALUE, matrix[i][j], getCost(i, n + j));
    }
  }
  for(int i = 0; i < m; i++)
  {
    AddEdge(n + 1 + i, n + m + 1, bs[n + i].cnt, sums[i], 0);
  }
}

bool answer;

int getEdgeCost(edge* edg)
{
  if(R(*edg) > 0)
  {
    return edg->cost;
  }
  return MAX_VALUE;
}

int getTotalCost()
{
  int result = 0;
  for(vector<edge*>::iterator it = edges.begin(); it != edges.end(); it++)
  {
    edge *current = *it;
    if(current->cost > 0)
    {
      result += current->flow * current->cost;
    }
  }
  return result;
}

void Solve()
{
  answer = false;
  BuildGraph();
  int before = getTotalCost();

  //Поиск цикла отриц веса
  __int64 d[209];
  memset(d, 0, sizeof(d));
  int p[209];
  int cntVertex = n + m + 2;
  int vertex = -1;
  for(int i = 0; i <= cntVertex; i++)
  {
    vertex = -1;
    int index = 0;
    for(vector<edge*>::iterator it = edges.begin(); it != edges.end(); it++)
    {
      edge *current = *it;
      if(d[current->to] > d[current->from] + getEdgeCost(current))
      {
        d[current->to] = max(-INF, d[current->from] + getEdgeCost(current));
        p[current->to] = current->from;
        vertex = current->to;
      }
      index++;
    }
  }
  if(vertex == -1)
  {
    return;
  }
  //Поиск цикла отриц веса

  answer = true;
  //printf("before: %d\n", before);

  //Поиск вершин в цикле
  for(int i = 0; i < n; i++)
  {
    vertex = p[vertex];
  }
  int copy = vertex;
  vector<int> path;
  while(true)
  {
    if(copy == vertex && path.size() > 1)
    {
      break;
    }
    path.push_back(graph[p[copy]][copy]);
    copy = p[copy];
  }
  reverse(path.begin(), path.end());
  //Поиск вершин в цикле

  int z = MAX_VALUE;
  for(vector<int>::iterator itPath = path.begin(); itPath != path.end(); itPath++)
  {
    edge *current = edges[*itPath];
    //printf("%d->%d\n", current->from, current->to);
    z = min(z, R(*current));
  }
  //printf("z: %d\n", z);
  for(vector<int>::iterator itPath = path.begin(); itPath != path.end(); itPath++)
  {
    edge *current = edges[*itPath];
    current->flow += z;
    current->reverse->flow -= z;
  }
  int after = getTotalCost();
  //printf("after: %d\n", after);

  //Рассчёт матрицы в ответе
  memset(matrix, 0, sizeof(matrix));
  for(vector<edge*>::iterator it = edges.begin(); it != edges.end(); it++)
  {
    edge *current = *it;
    if(current->from > 0 && current->from <= n
      && current->to > n && current->to < cntVertex)
    {
      matrix[current->from - 1][current->to - n - 1] = current->flow;
    }
  }
  //Рассчёт матрицы в ответе
}

void WriteData()
{
  if(answer)
  {
    printf("SUBOPTIMAL\n");
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
  }
  else
  {
    printf("OPTIMAL\n");
  }
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