#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int TREESIZE = 4 * MAXN;

int n;
__int64 a[TREESIZE];

void update(int index, int val, int pos, int l, int r)
{
  if(l == r)
  {
    a[index] = val;
    return;
  }
  int cnt = (r - l + 1) / 2;
  int newr = l + cnt - 1;
  int newl = l + cnt;
  if(pos <= newr)
  {
    update(index * 2 + 1, val, pos, l, newr);
  }
  else
  {
    update(index * 2 + 2, val, pos, newl, r);
  }
  a[index] = a[index * 2 + 1] + a[index * 2 + 2];
}

void ReadData()
{
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    update(0, val, i + 1, 1, MAXN);
  }
}

__int64 getSum(int index, int pl, int pr, int l, int r)
{
  if(pl > pr)
  {
    return 0LL;
  }
  if(pl == l && pr == r)
  {
    return a[index];
  }
  int cnt = (r - l + 1) / 2;
  int newr = l + cnt - 1;
  int newl = l + cnt;
  return getSum(index * 2 + 1, pl, min(pr, newr), l, newr)
    + getSum(index * 2 + 2, max(pl, newl), pr, newl, r);
}

void Solve()
{
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%I64d\n", getSum(0, l, r, 1, MAXN));
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  int QWE = 1;
  freopen("sum2.in", "r", stdin);
  freopen("sum2.out", "w", stdout);
  #ifndef ONLINE_JUDGE
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