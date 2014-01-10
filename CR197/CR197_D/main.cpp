#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[1200000];
int n, m, cnt;

bool Update(int pos, int value, int l, int r, int index)
{
  if(l == r)
  {
    a[index] = value;
    return true;
  }
  int cntLocal = (r - l + 1) / 2;
  bool result;
  int newr = l + cntLocal - 1, newl = r - cntLocal + 1;
  if(pos <= newr)
  {
    result = Update(pos, value, l, newr, index * 2 + 1);
  }
  else
  {
    result = Update(pos, value, newl, r, index * 2 + 2);
  }
  if(result)
  {
    a[index] = a[index * 2 + 1] | a[index * 2 + 2];
  }
  else
  {
    a[index] = a[index * 2 + 1] ^ a[index * 2 + 2];
  }
  return !result;
}

void ReadData()
{
  scanf("%d %d", &n, &m);
  memset(a, 0, sizeof(a));
  cnt = 1 << n;
  for(int i = 0; i < cnt; i++)
  {
    int val;
    scanf("%d", &val);
    Update(i + 1, val, 1, cnt, 0);
  }
}

void Solve()
{
  for(int i = 0; i < m; i++)
  {
    int p, b;
    scanf("%d %d", &p, &b);
    Update(p, b, 1, cnt, 0);
    printf("%d\n", a[0]);
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