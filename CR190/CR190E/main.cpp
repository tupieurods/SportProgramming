#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

struct vertex
{
  vector<int> links;
  int marked;
  int bfsVisited;
};

int n;
vertex v[100005];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    v[i].links.clear();
    v[i].marked = -1;
    v[i].bfsVisited = -1;
  }
  for(int i = 1; i < n; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    v[from].links.push_back(to);
    v[to].links.push_back(from);
  }
}

int d[100005], p[100005];
int bfsN;

int bfs(int start)
{
  bfsN++;
  queue<int> q;
  int result = start;
  //memset(d, 0xFF, sizeof(d));
  //memset(p, 0xFF, sizeof(p));//ѕри поиске не учитываетс€
  //“олько при определении центра
  d[start] = 0;
  p[start] = -2;
  q.push(start);

  while(!q.empty())
  {
    int current = q.front();
    q.pop();

    for(int i = 0; i < v[current].links.size(); i++)
    {
      if(v[v[current].links[i]].marked == -1
        && v[v[current].links[i]].bfsVisited < bfsN)
      {
        v[v[current].links[i]].bfsVisited = bfsN;
        d[v[current].links[i]] = d[current] + 1;
        if(d[v[current].links[i]] > d[result])
          result = v[current].links[i];
        p[v[current].links[i]] = current;
        q.push(v[current].links[i]);
      }
    }
  }
  return result;
}

int findCenter(int startVal)
{
  int y = bfs(startVal);
  if(y == startVal)
    return startVal;
  //printf("y: %d\n", y);
  int z = bfs(y);
  //printf("z: %d\n", z);
  int len = d[z] / 2 + d[z] % 2;
  for(int i = 0; i < len; i++)
  {
    z = p[z];
  }
  return z;
}

void Solve()
{
  memset(d, 0xFF, sizeof(d));
  memset(p, 0xFF, sizeof(p));
  bfsN = -1;
  int mainCenter = findCenter(0);
  //printf("main center: %d\n", mainCenter);
  v[mainCenter].marked = 0;
  vector<pair<int, int> > current;
  for(int i = 0; i < v[mainCenter].links.size(); i++)
  {
    current.push_back(make_pair(v[mainCenter].links[i], v[mainCenter].marked));
  }
  while(!current.empty())
  {
    vector<pair<int, int> > newCurrent;
    for(int i = 0; i < current.size(); i++)
    {
      //¬полне возможна така€ ситуаци€, что одна вершина была добавлена
      //два раза и же обработана
      if(v[current[i].first].marked != -1)
        continue;
      int center = findCenter(current[i].first);
      v[center].marked = current[i].second + 1;
      for(int j = 0; j < v[center].links.size(); j++)
      {
        if(v[v[center].links[j]].marked == -1)
        {
          newCurrent.push_back(make_pair(v[center].links[j], v[center].marked));
        }
      }
    }
    current = newCurrent;
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%c ", 'A' + v[i].marked);
  }
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