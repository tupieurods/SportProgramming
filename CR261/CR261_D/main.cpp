#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mapping;
map<int, int>::iterator mIt;
int n;
int a[1000009];
int l[1000009], /*r[1000009],*/ cnt[1000009];
int tree[4 * 1000009];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  mapping.clear();
  #endif
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    mIt = mapping.find(val);
    int toAdd = -1;
    if(mIt == mapping.end())
    {
      toAdd = mapping.size();
      mapping.insert(make_pair(val, toAdd));
    }
    else
    {
      toAdd = mIt->second;
    }
    a[i] = toAdd;
  }
}

__int64 answer;

void treeAdd(int tl, int tr, int pos, int idx, int val)
{
  if(tl == tr)
  {
    tree[idx] += val;
    return;
  }
  int center = tl + (tr - tl) / 2;
  if(center >= pos)
  {
    treeAdd(tl, center, pos, idx * 2, val);
  }
  else
  {
    treeAdd(center + 1, tr, pos, idx * 2 + 1, val);
  }
  tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int getSum(int tl, int tr, int ql, int qr, int idx)
{
  if(ql > qr)
  {
    return 0;
  }
  if(tl == ql && tr == qr)
  {
    return tree[idx];
  }
  int center = tl + (tr - tl) / 2;
  return getSum(tl, center, ql, min(qr, center), idx * 2)
    + getSum(center + 1, tr, max(center + 1, ql), qr, idx * 2 + 1);
}

void Solve()
{
  answer = 0;
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
    l[i] = cnt[a[i]];
    treeAdd(1, n, l[i], 1, 1);
  }
  memset(cnt, 0, sizeof(cnt));
  for(int i = n - 1; i >= 0; i--)
  {
    treeAdd(1, n, l[i], 1, -1);
    cnt[a[i]]++;
    //r[i] = cnt[a[i]];
    answer += getSum(1, n, cnt[a[i]] + 1, n, 1);
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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