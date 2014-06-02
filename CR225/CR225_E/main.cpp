#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[200009];
int n, m;
int a[200009];
int ftree[400009];//Время обработки не выйдет за число верших x2

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 200009; i++)
  {
    tree[i].clear();
  }
  #endif
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i + 1]);
  }
  for(int i = 1; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    tree[from].push_back(to);
    tree[to].push_back(from);
  }
}

bool visited[200009];
int timeStart[200009], timeFinish[200009], currentTime;
int level[200009];

void dfs(int cv)
{
  visited[cv] = true;
  timeStart[cv] = currentTime + 1;
  currentTime++;
  for(vector<int>::iterator it = tree[cv].begin(); it != tree[cv].end(); it++)
  {
    if(!visited[*it])
    {
      level[*it] = level[cv] + 1;
      dfs(*it);
    }
  }
  timeFinish[cv] = currentTime + 1;
  currentTime++;
}

void update(int pos, int val)
{
  while(pos < 400009)
  {
    ftree[pos] += val;
    pos += pos & -pos;
  }
}

int getCum(int pos)
{
  int result = 0;
  while(pos > 0)
  {
    result += ftree[pos];
    pos -= pos & -pos;
  }
  return result;
}

void Solve()
{
  currentTime = 0;
  memset(visited, 0, sizeof(visited));
  level[1] = 0;
  dfs(1);
  for(int i = 0; i < m; i++)
  {
    int type;
    scanf("%d", &type);
    if(type == 1)
    {
      int pos, val;
      scanf("%d %d", &pos, &val);
      if(level[pos] % 2 == 0)
      {
        update(timeStart[pos], val);
        update(timeFinish[pos], -val);
      }
      else
      {
        update(timeStart[pos], -val);
        update(timeFinish[pos], val);
      }
    }
    else
    {
      int pos;
      scanf("%d", &pos);
      if(level[pos] % 2 == 0)
      {
        printf("%d\n", a[pos] + getCum(timeStart[pos]));
      }
      else
      {
        printf("%d\n", a[pos] - getCum(timeStart[pos]));
      }
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