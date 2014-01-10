#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

using namespace std;

int n, m;

void ReadData()
{
  scanf("%d %d", &n, &m);
}

int answer[300009];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  set<int> vals;
  for(int i = 0; i < n; i++)
  {
    vals.insert(i + 1);
  }
  set<int>::iterator it;
  for(int i = 0; i < m; i++)
  {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    it = vals.lower_bound(l);
    while(it != vals.end())
    {
      if(*it != x)
      {
        answer[*it - 1] = x;
        int prev = *it;
        it++;
        vals.erase(prev);
      }
      else
      {
        it++;
      }
      if(it == vals.end() || *it > r)
      {
        break;
      }
    }
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", answer[i]);
  }
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
