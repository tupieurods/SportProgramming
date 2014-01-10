#include <stdio.h>
#include <stdlib.h>
#include <deque>

//#pragma comment(linker, "/STACK:500000")

using namespace std;

deque<int> *v;
bool *visited;
int n, m;
int status;
//bool cycle;

/*Ne hocnu dfs pisat, len
void dfs()
{
  visited = new bool[n];
  memset(visited, 0, sizeof(int) * n);
  int cnt = 0;
  cycle = false;
  visited[0] = true;

  for(int i = 0; i < n; i++)
  {
    for(int j = 0; i < v[i].size(); j++)
    if(!visited[i])
    {
      dfsVisit(i);
      cnt++;
    }
  }
  if(cnt == 1 && cycle)
    status = 1;
}

bool dfsVisit(int v)
{
  if(visited[v])
  {
    if(v == 0 && !cycle)
    {
      cycle = true;
      return true;
    }
    return false;
  }
  visited[v] = true;
  for(int)
  return false;
}*/

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
    //ReadData
    scanf("%d %d", &n, &m);
    status = 3;
    v = new deque<int>[n];
    for(int i = 0; i < m; i++)
    {
      int from, to;
      scanf("%d %d", &from, &to);
      from--;
      to--;
      v[from].push_back(to);
      v[to].push_back(from);
    }
    //Solve
    if((n == m) || (m == n - 1))
    {
      if(m == n - 1)//bus/star/unknown
      {
        int cnt1 = 0, cnt2 = 0;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
          if(v[i].size() == 1)
            cnt1++;
          if(v[i].size() == 2)
            cnt2++;
          if(v[i].size() == m)
            flag = true;
        }
        if(cnt1 == 2 && cnt2 == n - 2)
          status = 0;
        if(status == 3 && flag && cnt1 == n - 1)
          status = 2;
      }
      else//ring/unknown
      {
        //check for star topology
        int cnt2 = 0;
        for(int i = 0; i < n; i++)
        {
          if(v[i].size() == 2)
            cnt2++;
        }
        if(cnt2 == n)
          status = 1;
      }
    }
    //WriteData
    switch(status)
    {
      case 0:
      {
        printf("bus topology\n");
        break;
      }
      case 1:
      {
        printf("ring topology\n");
        break;
      }
      case 2:
      {
        printf("star topology\n");
        break;
      }
      case 3:
      {
        printf("unknown topology\n");
        break;
      }
    }
  }
  return 0;
}