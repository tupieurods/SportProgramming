#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k;
bool a[4009];

void ReadData()
{
  memset(a, 0, sizeof(a));
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++)
  {
    int type;
    scanf("%d", &type);
    int cnt = type == 1 ? 2 : 1;
    for(int j = 0; j < cnt; j++)
    {
      int val;
      scanf("%d", &val);
      a[val] = true;
    }
  }
}

int minimal, maximal;

void Solve()
{
  minimal = 0, maximal = 0;
  for(int i = 1; i < n; i++)
  {
    if(a[i] == false)
    {
      maximal++;
    }
  }
  for(int i = 1; i < n;)
  {
    if(a[i] == false)
    {
      minimal++;
      i++;
      if(i < n && a[i] == false)
      {
        i++;
      }
    }
    else
    {
      i++;
    }
  }
}

void WriteData()
{
  printf("%d %d\n", minimal, maximal);
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