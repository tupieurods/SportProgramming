#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int TREESIZE = 4 * MAXN;

int n;
__int64 a[TREESIZE];
__int64 b[MAXN];
__int64 stupidSol[MAXN];

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
  memset(stupidSol, 0, sizeof(stupidSol));
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    //int val;
    scanf("%I64d", &b[i + 1]);
    stupidSol[i + 1] = stupidSol[i] + b[i + 1];
    //update(0, val, i + 1, 1, MAXN);
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

void build(int index, int l, int r)
{
  if(l > r)
  {
    return;
  }
  if(l == r)
  {
    a[index] = b[l];
    return;
  }
  int cnt = (r - l + 1) / 2;
  int newr = l + cnt - 1;
  int newl = l + cnt;
  build(index * 2 + 1, l, newr);
  build(index * 2 + 2, newl, r);
  a[index] = a[index * 2 + 1] + a[index * 2 + 2];
}

void Solve()
{
  //build(0, 1, MAXN);
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    //printf("%I64d\n", getSum(0, l, r, 1, MAXN));
    printf("%I64d\n", stupidSol[r] - stupidSol[l - 1]);
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