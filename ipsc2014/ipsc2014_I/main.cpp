#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#pragma comment(linker, "/STACK:66777216")

int n;
int p[21009];
vector<int> v[21009];
vector<pair<int, int>> haff[21009];
vector<int> haffCost[21009];

void ReadData()
{
  for(int i = 0; i < 21009; i++)
  {
    v[i].clear();
  }
  for(int i = 0; i < 21009; i++)
  {
    haff[i].clear();
    haffCost[i].clear();
  }
  scanf("%d", &n);
  for(int i = 1; i < n; i++)
  {
    scanf("%d", &p[i]);
    v[p[i]].push_back(i + 1);
  }
}

int answer;
int dp1[21009];

void f2(int id, int vertex, int depth)
{
  if(vertex == -1)
  {
    return;
  }
  if(haff[id][vertex].first == -1 && haff[id][vertex].second == -1)
  {
    answer += depth * haffCost[id][vertex];
    return;
  }
  f2(id, haff[id][vertex].first, depth + 1);
  f2(id, haff[id][vertex].second, depth + 1);
}

int f(int vertex)
{
  dp1[vertex] = 1;
  priority_queue<pair<int, int>> q;
  int idx = 0;
  for(vector<int>::iterator it = v[vertex].begin(); it != v[vertex].end(); it++)
  {
    dp1[vertex] += f(*it);
    haff[vertex].push_back(make_pair(-1, -1));
    haffCost[vertex].push_back(dp1[*it]);
    q.push(make_pair(-dp1[*it], idx));
    idx++;
  }
  while(q.size() > 1)
  {
    pair<int, int> p1 = q.top();
    q.pop();
    pair<int, int> p2 = q.top();
    q.pop();
    haff[vertex].push_back(make_pair(p1.second, p2.second));
    q.push(make_pair(p1.first + p2.first, idx));
    idx++;
  }
  f2(vertex, idx - 1, 0);
  return dp1[vertex];
}

void Solve()
{
  answer = 0;
  memset(dp1, 0, sizeof(dp1));
  f(1);
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}