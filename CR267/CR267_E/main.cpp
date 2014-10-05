#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 500009

int n;
int a[MAXN], a2[MAXN];
int a2Cnt;
map<int, int> mapping;


void ReadData()
{
  scanf("%d", &n);
  a2Cnt = 0;
  mapping.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    if(mapping.find(a[i]) == mapping.end())
    {
      mapping.insert(make_pair(a[i], a2Cnt));
      a2[a2Cnt] = a[i];
      a2Cnt++;
    }
    a[i] = mapping[a[i]];
  }
}

int tree[4 * MAXN];

void upd(int tl, int tr, int idx, int tidx, int val)
{
  if(tl == tr)
  {
    tree[tidx] = val;
    return;
  }
  int center = tl + (tr - tl) / 2;
  if(idx <= center)
  {
    upd(tl, center, idx, tidx * 2, val);
  }
  else
  {
    upd(center + 1, tr, idx, tidx * 2 + 1, val);
  }
  tree[tidx] = max(tree[tidx * 2], tree[tidx * 2 + 1]);
}

int getMax(int tl, int tr, int ql, int qr, int tidx)
{
  if(tl > tr || ql > qr)
  {
    return -1;
  }
  if(tl == ql && tr == qr)
  {
    return tree[tidx];
  }
  int center = tl + (tr - tl) / 2;
  return max(getMax(tl, center, ql, min(center, qr), tidx * 2),
    getMax(center + 1, tr, max(center + 1, ql), qr, tidx * 2 + 1));
}

int b[MAXN], m;
int v[MAXN][5];

void Solve()
{
  m = 0;
  memset(v, 0, sizeof(v));
  memset(tree, 0xFF, sizeof(tree));
  int start = 0;
  for(int i = 0; i < n; i++)
  {
    if(v[a[i]][4] == 0)
    {
    }
    if(v[a[i]][4] != 0 && v[a[i]][v[a[i]][4] - 1] < start)
    {
      v[a[i]][4] = 0;
    }
    v[a[i]][v[a[i]][4]] = i;
    v[a[i]][4]++;
    if(v[a[i]][4] == 4)
    {
      start = i + 1;
      b[m * 4 + 0] = b[m * 4 + 1] = b[m * 4 + 2] = b[m * 4 + 3] = a[i];
      m++;
    }
    else
    {
      bool flag = false;
      for(int j = 0; j + 1 < v[a[i]][4]; j++)
      {
        int l = v[a[i]][j];
        if(l - 1 < start)
        {
          continue;
        }
        int p = getMax(0, n - 1, start, l - 1, 1);
        if(p > l && p < i)
        {
          b[m * 4 + 0] = b[m * 4 + 2] = a[p];
          b[m * 4 + 1] = b[m * 4 + 3] = a[i];
          m++;
          start = i + 1;
          flag = true;
          break;
        }
      }
      if(flag)
      {
        continue;
      }
      for(int j = 0; j < v[a[i]][4]; j++)
      {
        upd(0, n - 1, v[a[i]][j], 1, i);
      }
    }
  }
}

void WriteData()
{
  m *= 4;
  printf("%d\n", m);
  for(int i = 0; i < m; i++)
  {
    printf("%d ", a2[b[i]]);
  }
  printf("\n");
}

/*
3
14
15 11 1 16 12 10 8 2 13 14 10 8 2 18
4
3 5 3 5
10
35 1 2 1 2 35 100 200 100 200
*/

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n100000\n");
    for(int i = 0; i < 100000; i++)
    {
      printf("1000000000 ");
    }
    printf("\n");
    return 0;
  }
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