#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

#define OVER 0
#define NORMAL 1
#define LOWER 2

#pragma warning(disable: 4996)

using namespace std;

struct operation
{
  int from, to, val;
};

int n, v, e;
int a[309], b[309];
bool matrix[309][309];
bool answer;
vector<operation> answerOperations;

void presentationError()
{
  printf("Someone changed matrix.");
  exit(0);
}

void ReadData()
{
  memset(matrix, 0, sizeof(matrix));
  scanf("%d %d %d", &n, &v, &e);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < e; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    matrix[from][to] = true;
    matrix[to][from] = true;
  }
}

void dfsVisit(int vertex);
void fix();

vector<int> Over;
bool visited[309];
int visited2[309];
int currentStep;
__int64 costA, costB;
vector<int> component;
vector<int> way;

void dfs()
{
  memset(visited, 0, sizeof(visited));
  memset(visited2, 0, sizeof(visited2));
  currentStep = 0;
  for(int i = 0; i < n; i++)
  {
    if(visited[i] == false)
    {
      Over.clear();
      component.clear();
      costA = 0, costB = 0;
      dfsVisit(i);
      if(costA != costB)
      {
        answer = false;
        return;
      }
      fix();
    }
  }
}

void dfsVisit(int vertex)
{
  visited[vertex] = true;
  component.push_back(vertex);
  costA += a[vertex];
  costB += b[vertex];
  if(a[vertex] > b[vertex])
  {
    Over.push_back(vertex);
  }
  for(int i = 0; i < n; i++)
  {
    if(!visited[i] && matrix[vertex][i])
    {
      dfsVisit(i);
    }
  }
}

int last_ind;

void push_way(int start, int finish, int delta)
{
  if(start > finish)
  {
    return;
  }
  if(finish == last_ind)
  {
    push_way(start, finish - 1, delta);
    return;
  }
  int minus = min(delta, a[way[finish]]);
  a[way[finish]] -= minus;
  a[way[finish + 1]] += minus;
  operation toAdd = {way[finish], way[finish + 1], minus};
  answerOperations.push_back(toAdd);
  push_way(start, finish - 1, delta);
  if(minus != delta)
  {
    a[way[finish]] -= delta - minus;
    a[way[finish + 1]] += delta - minus;
    operation toAdd2 = {way[finish], way[finish + 1], delta - minus};
    answerOperations.push_back(toAdd2);
  }
}

void dfsVisit2(int vertex)
{
  visited2[vertex] = currentStep;
  way.push_back(vertex);
  if(a[vertex] < b[vertex])
  {
    last_ind = way.size() - 1;
    int delta1 = a[way[0]] - b[way[0]];
    int delta2 = b[way[last_ind]] - a[way[last_ind]];
    push_way(0, last_ind, min(delta1, delta2));
    if(a[way[0]] <= b[way[0]])
    {
      return;
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(visited2[i] != currentStep && matrix[vertex][i])
    {
      dfsVisit2(i);
      if(a[way[0]] <= b[way[0]])
      {
        return;
      }
    }
  }
  way.pop_back();
}

void fix()
{
  while(Over.size() != 0)
  {
    currentStep++;
    int val = Over[Over.size() - 1];
    Over.pop_back();
    dfsVisit2(val);
    way.clear();
  }
}

void Solve()
{
  answer = true;
  answerOperations.clear();
  dfs();
}

void WriteData()
{
  if(answer)
  {
    printf("%d\n", answerOperations.size());
    for(vector<operation>::iterator it = answerOperations.begin(); it != answerOperations.end(); it++)
    {
      printf("%d %d %d\n", it->from + 1, it->to + 1, it->val);
    }
    printf("\n");
  }
  else
  {
    printf("NO\n");
  }
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}