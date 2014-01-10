#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int a[200009], b[200009];
set<int> s;

void ReadData()
{
  scanf("%d", &n);
  s.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    b[i] = 0;
    s.insert(i);
  }
  scanf("%d", &m);
}

void Solve()
{
  set<int>::iterator it;
  for(int T = 0; T < m; T++)
  {
    int type;
    scanf("%d", &type);
    if(type == 1)
    {
      int k, val;
      scanf("%d %d", &k, &val);
      k--;
      while(true)
      {
        it = s.lower_bound(k);
        k++;
        if(it == s.end())
        {
          break;
        }
        int delta = a[*it] - b[*it];
        if(delta < val)
        {
          b[*it] += delta;
          val -= delta;
          s.erase(it);
        }
        else if(delta == val)
        {
          b[*it] = a[*it];
          s.erase(it);
          break;
        }
        else
        {
          b[*it] += val;
          break;
        }
      }
    }
    else if(type == 2)
    {
      int k;
      scanf("%d", &k);
      printf("%d\n", b[k - 1]);
    }
    else
    {
      throw;
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