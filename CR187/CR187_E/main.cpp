#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MOD 1000000007
#define MAXN 1000009

#pragma warning(disable: 4996)

using namespace std;

int n;
int tree[4 * MAXN];

void ReadData()
{
  memset(tree, 0, sizeof(tree));
  scanf("%d", &n);
}

void UpdateTree(int treeL, int treeR, int pos, int value, int ind)
{
  if(treeL == treeR)
  {
    tree[ind] = value;
    return;
  }
  int center = treeL + (treeR - treeL) / 2;
  if(pos <= center)
  {
    UpdateTree(treeL, center, pos, value, ind * 2 + 1);
  }
  else
  {
    UpdateTree(center + 1, treeR, pos, value, ind * 2 + 2);
  }
  tree[ind] = (tree[ind * 2 + 1] + tree[ind * 2 + 2]) % MOD;
}

int GetRangeSum(int treeL, int treeR, int l, int r, int ind)
{
  if(l > r)
  {
    return 0;
  }
  if(treeL == l && treeR == r)
  {
    return tree[ind];
  }
  int center = treeL + (treeR - treeL) / 2;
  return (GetRangeSum(treeL, center, l, min(r, center), ind * 2 + 1)
    + GetRangeSum(center + 1, treeR, max(l, center + 1), r, ind * 2 + 2)) % MOD;
}

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    int value;
    scanf("%d", &value);
    int newValue = GetRangeSum(1, MAXN, 1, value, 0);
    newValue = (newValue * 1LL * value + value) % MOD;
    UpdateTree(1, MAXN, value, newValue, 0);
  }
}

void WriteData()
{
  printf("%d\n", tree[0]);
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