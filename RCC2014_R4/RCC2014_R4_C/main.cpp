#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <deque>

using namespace std;

//#define LOCAL

int n, m;

void ReadData()
{
  scanf("%d %d", &n, &m);
}

deque<int> q[100009];

void Solve()
{
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    if(q[from].size() == 0)
    {
      q[to].push_back(from);
      printf("NO\n");
    }
    else
    {
      int val = q[from][0];
      q[from].pop_front();
      q[to].push_back(val);
      if(val == to)
      {
        printf("YES\n");
      }
      else
      {
        printf("NO\n");
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    q[i].clear();
  }
}

void WriteData()
{
  //printf("\n");
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}