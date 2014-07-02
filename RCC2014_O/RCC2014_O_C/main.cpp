#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int n, m, c, h, k;
int cold[100009], hot[100009];

void ReadData()
{
  scanf("%d %d %d %d %d", &n, &m, &c, &h, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &cold[i]);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &hot[i]);
  }
}

set<int> a[100009], b[100009];

__int64 gcd(__int64 v1, __int64 v2)
{
  return v2 == 0 ? v1 : gcd(v2, v1 % v2);
}

void Solve()
{
  sort(cold, cold + n);
  sort(hot, hot + m);
#ifndef ONLINE_JUDGE
  for(int i = 0; i < 100009; i++)
  {
    a[i].clear();
    b[i].clear();
  }
#endif
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j * 1LL * j <= cold[i]; j++)
    {
      if(cold[i] % j == 0)
      {
        a[j].insert(cold[i] / j);
        a[cold[i] / j].insert(j);
      }
    }
  }
  for(int i = 0; i < m; i++)
  {
    for(int j = 1; j * 1LL * j <= hot[i]; j++)
    {
      if(hot[i] % j == 0)
      {
        b[j].insert(hot[i] / j);
        b[hot[i] / j].insert(j);
      }
    }
  }
  for(int i = 0; i < k; i++)
  {
    int p, q;
    bool answer = false;
    scanf("%d %d", &p, &q);
    __int64 down = p - q * 1LL * c;
    __int64 top = -p + q * 1LL * h;
    if(top > 0 && down > 0)
    {
      __int64 d = gcd(top, down);
      top /= d;
      down /= d;
      if(top <= 100000 && down <= 100000)
      {
        p = top;
        q = down;
        for(set<int>::iterator it = a[p].begin(); it != a[p].end(); it++)
        {
          if(b[q].find(*it) != b[q].end())
          {
            answer = true;
            break;
          }
        }
      }
    }
    if(answer)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
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