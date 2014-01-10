#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

const int SHIT = 100000;
const __int64 INF = 1LL << 52;

struct edge
{
  int from, to;
  __int64 cost;
};

int n;
vector<edge*> edges;

void ReadData()
{
  edges.clear();
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int val;
      scanf("%d", &val);
      if(val == SHIT)
      {
        continue;
      }
      edge *toAdd = new edge;
      toAdd->from = i;
      toAdd->to = j;
      toAdd->cost = val;
      edges.push_back(toAdd);
    }
  }
}

bool answer;

void Solve()
{
  answer = false;
  __int64 d[109];
  memset(d, 0, sizeof(d));
  bool flag = false;
  for(int i = 0; i <= n; i++)
  {
    flag = false;
    for(vector<edge*>::iterator it = edges.begin(); it != edges.end(); it++)
    {
      edge *current = *it;
      if(d[current->to] > d[current->from] + current->cost)
      {
        d[current->to] = max(-INF, d[current->from] + current->cost);
        flag = true;
      }
    }
  }
  if(flag)
  {
    answer = true;
    return;
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  WriteData();
  return 0;
}