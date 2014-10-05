#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, q;
vector<int> edges[300009];
int p[300009], setRank[300009], d[300009];

void makeSet(int idx)
{
  p[idx] = idx;
  setRank[idx] = 0;
  d[idx] = 0;
}

int findSet(int idx)
{
  if(p[idx] != idx)
  {
    p[idx] = findSet(p[idx]);
  }
  return p[idx];
}

void unionSet(int idx1, int idx2, bool updateD = false)
{
  int p1 = findSet(idx1);
  int p2 = findSet(idx2);
  if(p1 == p2)
  {
    return;
  }
  if(setRank[p1] > setRank[p2])
  {
    p[p2] = p1;
    if(updateD)
    {
      d[p1] = max((d[p1] + 1) / 2 + (d[p2] + 1) / 2 + 1, max(d[p1], d[p2]));
    }
  }
  else
  {
    p[p1] = p2;
    if(updateD)
    {
      d[p2] = max((d[p1] + 1) / 2 + (d[p2] + 1) / 2 + 1, max(d[p1], d[p2]));
    }
  }
  if(setRank[p1] == setRank[p2])
  {
    setRank[p2]++;
  }
}

void ReadData()
{
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < n; i++)
  {
    #ifndef ONLINE_JUDGE
    edges[i].clear();
    #endif
    makeSet(i);
  }
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    edges[from].push_back(to);
    edges[to].push_back(from);
    unionSet(from, to);
  }
}

bool usedG[300009];
int usedL[300009];
int l[300009];
int currentStep;

pair<int, int> bfs(int idx)
{
  currentStep++;
  queue<int> q;
  q.push(idx);
  //memset(usedL, 0, sizeof(usedL));
  //memset(l, 0, sizeof(l));
  usedL[idx] = currentStep;
  l[idx] = 0;
  pair<int, int> result = make_pair(idx, 0);
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    for(vector<int>::iterator it = edges[current].begin(); it != edges[current].end(); ++it)
    {
      if(usedL[*it] != currentStep)
      {
        usedL[*it] = currentStep;
        usedG[*it] = true;
        q.push(*it);
        l[*it] = l[current] + 1;
        if(l[*it] > result.second)
        {
          result.first = *it;
          result.second = l[*it];
        }
      }
    }
  }
  return result;
}

void calcD(int idx)
{
  pair<int, int> result = bfs(idx);
  result = bfs(result.first);
  d[findSet(idx)] = result.second;
}

void Solve()
{
  currentStep = 0;
  memset(usedL, 0, sizeof(usedL));
  memset(usedG, 0, sizeof(usedG));
  for(int i = 0; i < n; i++)
  {
    if(!usedG[i])
    {
      calcD(i);
    }
  }
  for(int i = 0; i < q; i++)
  {
    int queryType;
    scanf("%d", &queryType);
    if(queryType == 1)
    {
      int X;
      scanf("%d", &X);
      X--;
      printf("%d\n", d[findSet(X)]);
    }
    else
    {
      int X, Y;
      scanf("%d %d", &X, &Y);
      X--;
      Y--;
      unionSet(X, Y, true);
    }
  }
}

void WriteData()
{
  printf("\n");
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