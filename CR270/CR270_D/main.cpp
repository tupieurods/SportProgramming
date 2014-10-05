#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int m[2009][2009];
__int64 m2[2009][2009];
vector<pair<int, int>> edges;
vector<pair<int, int>> redges[2009];


void ReadData()
{
  edges.clear();
  scanf("%d", &n);
  for(int row = 0; row < n; row++)
  {
    #ifndef ONLINE_JUDGE
    redges[row].clear();
    #endif
    for(int col = 0; col < n; col++)
    {
      scanf("%d", &m[row][col]);
      edges.push_back(make_pair(m[row][col], row * 10000 + col));
    }
  }
}

int r[2009], p[2009];
bool answer;

int findSet(int idx)
{
  if(p[idx] != idx)
  {
    p[idx] = findSet(p[idx]);
  }
  return p[idx];
}

void linkSets(int idx1, int idx2)
{
  if(r[idx1] > r[idx2])
  {
    p[idx2] = idx1;
  }
  else
  {
    p[idx1] = idx2;
  }
  if(r[idx1] == r[idx2])
  {
    r[idx2]++;
  }
}

void unionSet(int idx1, int idx2)
{
  int _idx1 = findSet(idx1);
  int _idx2 = findSet(idx2);
  if(_idx1 != _idx2)
  {
    linkSets(_idx1, _idx2);
  }
}

int visited[2009];

void bfs(int idx)
{
  visited[idx] = idx;
  queue<int> q;
  m2[idx][idx] = 0;
  q.push(idx);
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    for(vector<pair<int, int>>::iterator it = redges[current].begin(); it != redges[current].end(); ++it)
    {
      if(visited[it->first] != idx)
      {
        visited[it->first] = idx;
        m2[idx][it->first] = m2[idx][current] + it->second;
        q.push(it->first);
      }
    }
  }
}

void Solve()
{
  answer = true;
  /*for(int i = 0; i < n; i++)
  {
    if(m[i][i] != 0)
    {
      answer = false;
      return;
    }
  }*/
  for(int row = 0; row < n; row++)
  {
    for(int col = 0; col < n; col++)
    {
      if(m[row][col] != m[col][row] || (row != col && m[row][col] == 0))
      {
        answer = false;
        return;
      }
    }
  }
  sort(edges.begin(), edges.end());
  for(int i = 0; i < n; i++)
  {
    p[i] = i;
    r[i] = 0;
  }
  for(vector<pair<int, int>>::iterator it = edges.begin(); it != edges.end(); ++it)
  {
    int from = it->second / 10000, to = it->second % 10000;
    if(findSet(from) != findSet(to))
    {
      unionSet(from, to);
      redges[from].push_back(make_pair(to, it->first));
      redges[to].push_back(make_pair(from, it->first));
    }
  }
  /*for(int i = 1; i < n; i++)
  {
    if(findSet(0) != findSet(i))
    {
      answer = false;
      return;
    }
  }*/
  memset(visited, 0xFF, sizeof(visited));
  for(int row = 0; row < n; row++)
  {
    bfs(row);
    for(int col = 0; col < n; col++)
    {
      if(m[row][col] != m2[row][col])
      {
        answer = false;
        return;
      }
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
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