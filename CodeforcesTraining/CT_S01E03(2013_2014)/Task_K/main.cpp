#include <stdio.h>
#include <stdlib.h>

struct vertex
{
  int sum, pref_sum, suff_sum, ans;
};

int n, maximal;
const int MAXN = 1 << 18;
const int TREESIZE = MAXN * 4;
vertex tree[TREESIZE];

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

vertex combine(vertex v1, vertex v2)
{
  vertex result;
  result.sum = v1.sum + v2.sum;
  result.pref_sum = max(v1.pref_sum, v1.sum + v2.pref_sum);
  result.suff_sum = max(v2.suff_sum, v2.sum + v1.suff_sum);
  result.ans = max(max(v1.ans, v2.ans), v1.suff_sum + v2.pref_sum);
  return result;
}

void updateTree(int index, int pos, int bl, int br, int val)
{
  if(bl == br)
  {
    tree[index].sum = val;
    tree[index].pref_sum = tree[index].suff_sum = tree[index].ans = max(0, val);
    return;
  }
  int localCenter = bl + (br - bl) / 2;
  if(pos <= localCenter)
  {
    updateTree(index * 2 + 1, pos, bl, localCenter, val);
  }
  else
  {
    updateTree(index * 2 + 2, pos, localCenter + 1, br, val);
  }
  tree[index] = combine(tree[index * 2 + 1], tree[index * 2 + 2]);
}

bool ReadData()
{
  scanf("%d", &n);
  if(n == 0)
  {
    return false;
  }
  maximal = -1000000000;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    maximal = max(maximal, val);
    updateTree(0, i + 1, 1, MAXN, val);
  }
  return true;
}

vertex getMax(int index, int l, int r, int bl, int br)
{
  if(l == bl && r == br)
  {
    return tree[index];
  }
  int localCenter = bl + (br - bl) / 2;
  if(r <= localCenter)
  {
    return getMax(index * 2 + 1, l, localCenter, bl, localCenter);
  }
  if(l > localCenter)
  {
    return getMax(index * 2 + 2, localCenter + 1, r, localCenter + 1, br);
  }
  return combine(getMax(index * 2 + 1, l, localCenter, bl, localCenter),
    getMax(index * 2 + 2, localCenter + 1, r, localCenter + 1, br));
}

int answer;

void Solve()
{
  if(maximal < 0)
  {
    answer = maximal;
    return;
  }
  answer = getMax(0, 1, n, 1, MAXN).ans;
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  /*#ifndef ONLINE_JDUGE
  freopen("input.txt", "r", stdin);
  #endif*/
  for(int i = 0; i < TREESIZE; i++)
  {
    tree[i].sum = tree[i].pref_sum = tree[i].suff_sum = tree[i].ans = 0;
  }
  while(ReadData())
  {
    Solve();
    WriteData();
  }
  return 0;
}