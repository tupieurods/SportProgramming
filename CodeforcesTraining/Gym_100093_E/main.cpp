#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int TREESIZE = MAXN * 4;

int n, m, u, v;
int table[TREESIZE];

void update(int index, int pos, int l, int r, int value)
{
  if(l == r)
  {
    table[index] = value;
    return;
  }
  int cntLocal = (r - l + 1) / 2;
  int newl = l + cntLocal, newr = l + cntLocal - 1;
  if(pos <= newr)
  {
    update(index * 2 + 1, pos, l, newr, value);
  }
  else
  {
    update(index * 2 + 2, pos, newl, r, value);
  }
  table[index] = min(table[index * 2 + 1], table[index * 2 + 2]);
}

void ReadData()
{
  for(int i = 0; i < TREESIZE; i++)
  {
    table[i] = 2000000000;
  }
  scanf("%d %d", &n, &m);
  int a;
  scanf("%d", &a);
  update(0, 1, 1, MAXN, a);
  for(int i = 1; i < n; i++)
  {
    a = (23LL * a + 21563LL) % 16714589LL;
    //printf("%I64d\n", a);
    update(0, i + 1, 1, MAXN, a);
  }
  scanf("%d %d", &u, &v);
}

int getMin(int index, int l, int r, int tl, int tr)
{
  if(l > r)
  {
    return 2000000000;
  }
  if(tl == l && r == tr)
  {
    return table[index];
  }
  int cntLocal = (tr - tl + 1) / 2;
  int newl = tl + cntLocal, newr = tl + cntLocal - 1;
  return min(getMin(index * 2 + 1, l, min(r, newr), tl, newr),
    getMin(index * 2 + 2, max(l, newl), r, newl, tr));
}

int answer;

void Solve()
{
  for(int i = 1; i <= m; i++)
  {
    answer = getMin(0, min(u, v), max(u, v), 1, MAXN);
    //printf(":%I64d %I64d\t", u, v);
    //printf("%I64d\n", answer);
    if(i != m)
    {
      u = ((17LL * u + 751LL + answer + 2LL * i) % n) + 1LL;
      v = ((13LL * v + 593LL + answer + 5LL * i) % n) + 1LL;
    }
  }
}

void WriteData()
{
  printf("%d %d %d\n", u, v, answer);
}

int main()
{
  int QWE = 1;
  freopen("sparse.in", "r", stdin);
  freopen("sparse.out", "w", stdout);
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