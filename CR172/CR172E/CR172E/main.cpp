#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <deque>

using namespace std;

deque<int>* lists;
int n;
double answer;

void ReadData()
{
  scanf("%d", &n);
  lists = new deque<int>[n];
  for(int i = 1; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    lists[from].push_back(to);
    lists[to].push_back(from);
  }
}

void dfsVisit(int, int);
bool* used;
void dfs()
{
  used = new bool[n];
  memset(used, 0, sizeof(bool) * n);
  used[0] = true;

  for(deque<int>::iterator it = lists[0].begin(); it != lists[0].end(); it++)
  {
    if(!used[*it])
    {
      dfsVisit(*it, 2);
    }
  }
}

void dfsVisit(int vertex, int depth)
{
  used[vertex] = true;
  answer += 1.0 / (double)depth;

  for(deque<int>::iterator it = lists[vertex].begin(); it != lists[vertex].end(); it++)
  {
    if(!used[*it])
    {
      dfsVisit(*it, depth + 1);
    }
  }
}

void Solve()
{
  answer = 1.0;
  dfs();
}

void WriteData()
{
  printf("%.10f\n", answer);
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