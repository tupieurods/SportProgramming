#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
#include <deque>
#include <limits.h>

using namespace std;

set<int>* data;
deque<int>* shit;
bool* visited;
int n, m;
int answer;

void dfsVisit(int v);

void dfs()
{
  memset(visited, 0, sizeof(bool) * n);
  for(int i = 0; i < n; i++)
  {
    if(!visited[i] && shit[i].size() != 0)
    {
      dfsVisit(i);
      answer++;
    }
  }
}

void dfsVisit(int v)
{
  visited[v] = true;
  for(int j = 0; j < shit[v].size(); j++)
  {
    for(set<int>::iterator it = data[shit[v][j]].begin(); it != data[shit[v][j]].end(); it++)
    {
      if(!visited[*it])
        dfsVisit(*it);
    }
  }
}

int main()
{
  scanf("%d %d", &n, &m);
  data = new set<int>[m + 1];
  shit = new deque<int>[n];
  visited = new bool[n];
  for(int i = 0; i < n; i++)
  {
    int k;
    scanf("%d", &k);
    for(int j = 0; j < k; j++)
    {
      int a;
      scanf("%d", &a);
      shit[i].push_back(a);
      data[a].insert(i);
    }
  }
  int zero = 0;
  for(int i = 0; i < n; i++)
  {
    if(shit[i].size() == 0)
      zero++;
  }
  if(zero == n)
  {
    printf("%d", n);
    return 0;
  }
  answer = -1;
  dfs();
  printf("%d", answer + zero);
  return 0;
}
