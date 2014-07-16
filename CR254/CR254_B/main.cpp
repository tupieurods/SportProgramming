#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v[59];
int n, m;

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 59; i++)
  {
    v[i].clear();
  }
  #endif
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    v[from].push_back(to);
    v[to].push_back(from);
  }
}

__int64 answer;
bool used[59];

void dfsVisit(int vertex)
{
  used[vertex] = true;
  for(vector<int>::iterator it = v[vertex].begin(); it != v[vertex].end(); it++)
  {
    if(!used[*it])
    {
      answer <<= 1;
      dfsVisit(*it);
    }
  }
}

void Solve()
{
  memset(used, 0, sizeof(used));
  answer = 1LL;
  for(int i = 0; i < n; i++)
  {
    if(!used[i])
    {
      dfsVisit(i);
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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