#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> inter;

void ReadData()
{
  scanf("%d", &n);
  inter.clear();
}

bool visited[100];

inline bool check(int l, int r)
{
  return (inter[l].first > inter[r].first && inter[l].first < inter[r].second)
    || (inter[l].second > inter[r].first && inter[l].second < inter[r].second);
}

bool bfs(int l, int r)
{
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  q.push(l);
  int cnt = inter.size();
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    visited[current] = true;

    for(int i = 0; i < cnt; i++)
    {
      if(!visited[i])
      {
        if(check(current, i))
        {
          if(i == r)
            return true;
          q.push(i);
        }
      }
    }
  }
  return false;
}

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    int type, l, r;
    scanf("%d %d %d", &type, &l, &r);
    switch(type)
    {
      case 1:
      inter.push_back(make_pair(l, r));
      break;
      case 2:
      if(bfs(l - 1, r - 1))
        printf("YES\n");
      else
        printf("NO\n");
      break;
    }
  }
}

void WriteData()
{
  printf("\n");
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