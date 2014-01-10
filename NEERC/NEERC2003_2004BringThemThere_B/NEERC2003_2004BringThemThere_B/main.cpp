#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>
#include <time.h>
#include <algorithm>

#define Size(v) ((int)v.size())
#define R(v) (v->c - v->f)

struct edge
{
  int from, to;
  int c, f;
  int StartTime, FinishTime;
  edge* reverse;
  edge* opposite;
};

using namespace std;

const int inf = (int)1e7;

int n, m, k, s, t, answerTime, flow, maxTime;
bool** matrix;
int** p;
deque<edge*> edges;
deque<int>** vertecies;
deque<pair<int, int>>* answer;
int** vertical;

void dfsVisit(int, int, int, bool(*func)(edge*));

bool comparer(int a, int b)
{
  return edges[a]->c > edges[b]->c;
}

void AddEdge(int from, int to, int capacity, int time)
{
  edge* newEdge = new edge;
  newEdge->from = from;
  newEdge->to = to;
  newEdge->c = capacity;
  newEdge->f = 0;
  newEdge->StartTime = time;
  newEdge->FinishTime = time + 1;

  edge* reverseEdge = new edge;
  newEdge->reverse = reverseEdge;

  reverseEdge->from = to;
  reverseEdge->to = from;
  reverseEdge->c = 0;
  reverseEdge->f = 0;
  reverseEdge->StartTime = time + 1;
  reverseEdge->FinishTime = time;
  reverseEdge->reverse = newEdge;

  edges.push_back(newEdge);
  vertecies[from][time].push_back(edges.size() - 1);
  edges.push_back(reverseEdge);
  vertecies[to][time + 1].push_back(edges.size() - 1);
}

void AddEdgeWithOpposite(int from, int to, int capacity, int time)
{
  AddEdge(from, to, capacity, time);
  AddEdge(to, from, capacity, time);
  edges[edges.size() - 1]->opposite = edges[edges.size() - 3];
  edges[edges.size() - 3]->opposite = edges[edges.size() - 1];
  edges[edges.size() - 2]->opposite = edges[edges.size() - 4];
  edges[edges.size() - 4]->opposite = edges[edges.size() - 2];
}

void BuildGraph()
{
  vertecies = new deque<int>*[n];
  for(int i = 0; i < n; i++)
  {
    vertecies[i] = new deque<int>[maxTime + 1];
  }
  edges.clear();
  //int*** matrixInd = new int**[n];
  for(int from = 0; from < n; from++)
  {
    //matrixInd[from] = new int*[maxTime];
    for(int time = 1; time < maxTime; time++)
    {
      //matrixInd[from][time] = new int[n];
      //memset(matrixInd[from][time], 0xFF, sizeof(int) * n);
      for(int to = from + 1; to < n; to++)
      {
        if(matrix[from][to])
        {
          //AddEdge(from, to, 1, time);
          //matrixInd[from][time][to] = edges.size() - 2;
          AddEdgeWithOpposite(from, to, 1, time);
        }
      }
      AddEdge(from, from, inf, time);
      vertical[from][time] = edges.size() - 2;
    }
  }

  for(int from = 0; from < n; from++)
  {
    for(int time = 1; time < maxTime; time++)
    {
      sort(vertecies[from][time].begin(), vertecies[from][time].end(), comparer);
    }
  }
  /*for(int from = 0; from < n; from++)
  {
    for(int time = 1; time < maxTime; time++)
    {
      for(int to = 0; to < n; to++)
      {
        if(matrixInd[from][time][to] != -1)
        {
          edges[matrixInd[from][time][to]]->opposite = edges[matrixInd[to][time][from]];
          edges[matrixInd[from][time][to]]->reverse->opposite = edges[matrixInd[to][time][from] + 1];
        }
      }
    }
  }*/
}

bool compareFoldFulkerson(edge* current)
{
  return ((R(current)) > 0);
}

bool comparePathFinder(edge* current)
{
  return (current->f > 0);
}

//int dfsCounter;

void dfs(bool(*func)(edge*))
{
  for(int i = 0; i < n; i++)
  {
    memset(p[i], 0xFF, sizeof(int) * maxTime);
  }
  p[s][1] = -2;
  
  for(int i = 0; i < Size(vertecies[s][1]); i++)
  {
    edge* current = edges[vertecies[s][1][i]];
    if(func(current))
    {
      dfsVisit(current->to, current->FinishTime, vertecies[s][1][i], func);
      if(p[t][answerTime + 1] != -1)
      {
        break;
      }
    }
  }
  
}

void dfsVisit(int v, int time, int edg, bool(*func)(edge*))
{
  if(p[v][time] != -1)
  {
    return;
  }
  //dfsCounter++;
  p[v][time] = edg;
  for(int i = 0; i < Size(vertecies[v][time]); i++)
  {
    edge* current = edges[vertecies[v][time][i]];
    if((current->StartTime <= answerTime) && func(current))
    {
      dfsVisit(current->to, current->FinishTime, vertecies[v][time][i], func);
      if(p[t][answerTime + 1] != -1)
      {
        break;
      }
    }
  }
}

int FordFulkerson()
{
  //int curr = 0;
  //dfsCounter = 0;
  //int fulkersonCounter = 0;
  while(true)
  {
    //fulkersonCounter++;
    //clock_t tt = clock();
    dfs(compareFoldFulkerson);
    //tt = clock() - tt;
    //curr++;
    if(p[t][answerTime + 1] == -1)
    {
      break;
    }
    int currentVertex = t;
    int currentTime = answerTime + 1;
    int minimal = 1005;
    while(p[currentVertex][currentTime] >= 0)
    {
      edge* current = edges[p[currentVertex][currentTime]];
      minimal = min(minimal, R(current));
      currentVertex = current->from;
      currentTime = current->StartTime;
    }

    currentVertex = t;
    currentTime = answerTime + 1;
    while(p[currentVertex][currentTime] >= 0)
    {
      edge* current = edges[p[currentVertex][currentTime]];
      current->f += minimal;
      current->reverse->f -= minimal;
      currentVertex = current->from;
      currentTime = current->StartTime;
    }
    //printf("dfs ¹: %d: %f s.\n", curr, ((float)tt) / CLOCKS_PER_SEC);
  }
  //printf("dfsCounter: %d\n", dfsCounter);
  //printf("fulkersonCounter: %d\n", fulkersonCounter);
  int res = 0;
  for(int i = 0; i < vertecies[s][1].size(); i++)
  {
    edge* current = edges[vertecies[s][1][i]];
    if(current->f > 0)
    {
      res += current->f;
    }
  }
  return res;
}

void ResetFlow()
{
  for(int i = 0; i < edges.size(); i++)
  {
    edges[i]->f = 0;
  }
}

void ExtendFlow()
{
  for(int i = 0; i < Size(vertecies[t][answerTime]); i++)
  {
    edge* current = edges[vertecies[t][answerTime][i]];
    if(current->FinishTime == answerTime + 1 && current->to == t)
    {
      current->f = flow;
      current->reverse->f = -flow;
      break;
    }
  }
}

void SolveFordFulkersonLinear()
{
  answerTime = 0;
  flow = 0;
  while(flow < k)
  {
    answerTime++;
    ResetFlow();
    flow = FordFulkerson();
  }
}

void SolveFordFulkersonExtend()
{
  answerTime = 0;
  flow = 0;
  ResetFlow();
  while(flow < k)
  {
    answerTime++;
    ExtendFlow();
    flow = FordFulkerson();
  }
}

void SolveFordFulkersonBinarySearch()
{
  answerTime = 0;
  flow = 0;
  int left = 1;
  int right = maxTime - 1;
  //int countWhile = 0;
  while(right > left)
  {
    //answerTime++;
    //printf("left: %d right: %d\n", left, right);
    //countWhile++;
    answerTime = left + (right - left) / 2;
    //clock_t tt = clock();
    ResetFlow();
    //tt = clock() - tt;
    //printf("Flow reset: %f s.\n", ((float)tt) / CLOCKS_PER_SEC);
    //tt = clock();
    flow = FordFulkerson();
    //tt = clock() - tt;
    //printf("FordFulkerson: %f s.\n", ((float)tt) / CLOCKS_PER_SEC);
    if(flow == k)
    {
      return;
    }
    else if(flow < k)
    {
      left = answerTime + 1;
    }
    else
    {
      right = answerTime;
    }
  }
  //printf("Iterations: %d\n", countWhile);
  answerTime = right;
  //clock_t tt = clock();
  ResetFlow();
  //tt = clock() - tt;
  //printf("Last Flow reset: %f s.\n", ((float)tt) / CLOCKS_PER_SEC);
  //tt = clock();
  flow = FordFulkerson();
  //tt = clock() - tt;
  //printf("Last FordFulkerson: %f s.\n", ((float)tt) / CLOCKS_PER_SEC);
}

void Solve()
{
  maxTime = n + k + 5;
  p = new int*[n];
  vertical = new int*[n];
  for(int i = 0; i < n; i++)
  {
    p[i] = new int[maxTime];
    vertical[i] = new int[maxTime];
    memset(vertical[i], 0xFF, sizeof(int) * maxTime);
  }
  //clock_t tt = clock();
  BuildGraph();
  //tt = clock() - tt;
  //printf("Graph builder: %.10f s.\n", ((float)tt) / CLOCKS_PER_SEC);
  //SolveFordFulkersonExtend();
  //SolveFordFulkersonLinear();
  SolveFordFulkersonBinarySearch();
}

void ReadData()
{
  scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
  s--;
  t--;
  matrix = new bool*[n];
  for(int i = 0; i < n; i++)
  {
    matrix[i] = new bool[n];
    memset(matrix[i], 0, sizeof(bool) * n);
  }
  for(int i = 0; i < m; i++)
  {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    v1--;
    v2--;
    matrix[v1][v2] = true;
    matrix[v2][v1] = true;
  }
}

int currentShip;

void WriteData()
{
  for(int i = 0; i < Size(edges); i++)
  {
    edge* current = edges[i];
    if(current->to != current->from)
    {
      if((current->f > 0) && (current->opposite->f > 0))
      {
        edges[vertical[current->from][current->StartTime]]->f += current->f;
        edges[vertical[current->from][current->StartTime]]->reverse->f -= current->f;
        edges[vertical[current->opposite->from][current->opposite->StartTime]]->f += current->opposite->f;
        edges[vertical[current->opposite->from][current->opposite->StartTime]]->reverse->f -= current->opposite->f;
        current->reverse->f = 0;
        current->opposite->reverse->f = 0;
        current->f = 0;
        current->opposite->f = 0;
      }
    }
  }
  printf("%d\n", answerTime);
  answer = new deque<pair<int, int>>[answerTime];
  for(int i = 0; i < k; i++)
  {
    currentShip = i + 1;
    dfs(comparePathFinder);
    int currentVertex = t;
    int currentTime = answerTime + 1;
    while(p[currentVertex][currentTime] >= 0)
    {
      edge* current = edges[p[currentVertex][currentTime]];
      current->f--;
      current->reverse->f++;
      if(current->c != inf)
      {
        answer[current->StartTime - 1].push_back(make_pair(currentShip, currentVertex));
      }
      currentVertex = current->from;
      currentTime = current->StartTime;
    }
  }
  for(int i = 0; i < answerTime; i++)
  {
    printf("%d ", answer[i].size());
    for(int j = 0; j < answer[i].size(); j++)
    {
      printf("%d %d  ", answer[i][j].first, answer[i][j].second + 1);
    }
    printf("\n");
  }
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
#ifndef ONLINE_JUDGE
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  //clock_t tt;
  for(int T = 0; T < QWE; T++)
  {
    //tt = clock();
    ReadData();
    //tt = clock() - tt;
    //printf("Read data: %.10f s.\n", ((float)tt) / CLOCKS_PER_SEC);
    //tt = clock();
    Solve();
    //tt = clock() - tt;
    //printf("Solving: %.10f s.\n", ((float)tt) / CLOCKS_PER_SEC);
    //tt = clock();
    WriteData();
    //tt = clock() - tt;
    //printf("Write answer: %.10f s.\n", ((float)tt) / CLOCKS_PER_SEC);
    //printf("edges count: %d\n", Size(edges));
  }
  return 0;
}