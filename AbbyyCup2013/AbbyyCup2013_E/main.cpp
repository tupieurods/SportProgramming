#include <stdio.h>
#include <string.h>

int n, m;
int *a;
const int mod = 1000000000;

__int64 cache[105];

void ReadData()
{
  scanf("%d %d", &n, &m);
  a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

__int64 f(int val)
{
  if(cache[val] != -1)
  {
    return cache[val];
  }
  __int64 result = (f(val - 1) + f(val - 2) % mod);
  cache[val] = result;
  return result;
}

void Solve()
{
  for(int i = 0; i < m; i++)
  {
    int t;
    scanf("%d", &t);
    switch(t)
    {
    case 1:
      int x, v;
      scanf("%d %d", &x, &v);
      a[x - 1] = v;
      break;
    case 2:
      {
        int l, r;
        scanf("%d %d", &l, &r);
        __int64 local = 0;
        for(int x = 0; x <= r - l; x++)
        {
          local += ((__int64)cache[x] * a[l + x - 1]) % mod;
          local %= mod;
        }
        printf("%I64d\n", local);
        break;
      }
    case 3:
      printf("presentation error\n");
      break;
    }
  }
}

void WriteData()
{
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
  memset(cache, 0xFF, sizeof(cache));
  cache[0] = 1;
  cache[1] = 1;
  for(int i = 100; i > 1; i--)
  {
    f(i);
    //printf("%I64d\n", f(i));
  }
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}