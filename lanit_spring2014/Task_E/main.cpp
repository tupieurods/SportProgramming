#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>

bool a[100009];
bool b[100009][330];
int n, m, d;
char str[100009];

void ReadData()
{
  scanf("%d%*c", &n);
  scanf("%s%*c", str);
  for(int i = 0; i < n; i++)
  {
    a[i] = str[i] == '1';
  }
  scanf("%d%*c", &m);
}

void update(int l, int r, int k)
{
  if(k >= d)
  {
    for(int i = l; i <= r; i += k)
    {
      a[i] = !a[i];
    }
    return;
  }
  int dist = (r - l) / k;
  b[l][k] = !b[l][k];
  int newR = l + k * (dist + 1);
  if(newR <= 100008)
  {
    b[newR][k] = !b[newR][k];
  }
}

bool status[330];

void realUpdate()
{
  for(int j = 1; j < d; j++)
  {
    memset(status, 0, sizeof(status));
    for(int i = 0; i < n; i++)
    {
      int k = i % j;
      if(b[i][j])
      {
        status[k] = !status[k];
      }
      if(status[k])
      {
        a[i] = !a[i];
      }
      b[i][j] = false;
    }
  }
}

void Solve()
{
  d = (int)sqrt((double)n) + 1;
  memset(b, 0, sizeof(b));
  for(int i = 0; i < m; i++)
  {
    scanf("%s%*c", str);
    if(str[0] == 'o')
    {
      realUpdate();
      for(int T = 0; T < n; T++)
      {
        printf("%d", a[T] ? 1 : 0);
      }
      printf("\n");
    }
    else
    {
      int idx = 0;
      int len = strlen(str);
      int l = 0, r = 0, k = 0;
      for(int j = 0; j < len; j++)
      {
        l = l * 10 + (int)(str[j] - '0');
      }
      scanf("%d %d%*c", &r, &k);
      l--;
      r--;
      update(l, r, k);
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
  //freopen("output.txt", "w", stdout);
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