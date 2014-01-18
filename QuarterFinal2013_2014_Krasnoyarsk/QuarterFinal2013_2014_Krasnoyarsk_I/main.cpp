#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

int n, m;
map<int, int> verticies[1000];
int realM;

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    verticies[i].clear();
  }
  for(int i = 0; i < m; i++)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--;
    b--;
    if(verticies[a].find(b) != verticies[a].end())
    {
      verticies[a][b] = min(c, verticies[a][b]);
    }
    else
    {
      verticies[a][b] = c;
    }
    if(verticies[b].find(a) != verticies[b].end())
    {
      verticies[b][a] = min(c, verticies[b][a]);
    }
    else
    {
      verticies[b][a] = c;
    }
  }
}

int answer;
int lens[1000];

bool compare(int v1, int v2)
{
  return lens[v1] == lens[v2] ? v1 < v2 : lens[v1] < lens[v2];
}

void Solve()
{
  answer = -1;
  if(m == 0)
  {
    return;
  }
  set<int, tr1::function<bool(int, int)>> pq(compare);
  bool used[1000];
  for(int T = 0; T < n; T++)
  {
    for(int i = 0; i < n; i++)
    {
      lens[i] = INT_MAX;
    }
    memset(used, 0, sizeof(used));
    lens[T] = 0;
    pq.insert(T);
    while(!pq.empty())
    {
      int current = *pq.begin();
      used[current] = true;
      pq.erase(pq.begin());
      answer = max(answer, lens[current]);

      for(map<int, int>::iterator it = verticies[current].begin(); it != verticies[current].end(); it++)
      {
        if(lens[it->first] > lens[current] + it->second && used[it->first] == false)
        {
          if(pq.find(it->first) != pq.end())
          {
            pq.erase(it->first);
          }
          lens[it->first] = lens[current] + it->second;
          pq.insert(it->first);
        }
      }
    }
    /*for(int i = 0; i < n; i++)
    {
      printf("%d ", lens[i]);
    }
    printf("\n");*/
  }
}

void WriteData()
{
  printf("%d\n", answer == 0 ? -1 : answer);
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