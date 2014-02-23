#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 1000009;

int n, k;
int pos[MAXN];
bool inTrash[MAXN];
int tree[MAXN * 4];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    pos[val] = i;
    inTrash[val] = true;
  }
  for(int i = 0; i < k; i++)
  {
    int val;
    scanf("%d", &val);
    inTrash[val] = false;
  }
}

void addTree(int treeL, int treeR, int treeIndex, int pos, int val)
{
  if(treeL == pos && treeR == pos)
  {
    tree[treeIndex] = val;
    return;
  }
  int treeCenter = treeL + (treeR - treeL) / 2;
  if(pos <= treeCenter)
  {
    addTree(treeL, treeCenter, treeIndex * 2 + 1, pos, val);
  }
  else
  {
    addTree(treeCenter + 1, treeR, treeIndex * 2 + 2, pos, val);
  }
  tree[treeIndex] = tree[treeIndex * 2 + 1] + tree[treeIndex * 2 + 2];
}

int treeGet(int treeL, int treeR, int l, int r, int treeIndex)
{
  if(l > r)
  {
    return 0;
  }
  if(treeL == l && treeR == r)
  {
    return tree[treeIndex];
  }
  int treeCenter = treeL + (treeR - treeL) / 2;
  return treeGet(treeL, treeCenter, l, min(r, treeCenter), treeIndex * 2 + 1)
    + treeGet(treeCenter + 1, treeR, max(treeCenter + 1, l), r, treeIndex * 2 + 2);
}

__int64 answer;

void Solve()
{
  answer = 0;
  set<int> ranges;
  set<int>::iterator it;
  ranges.insert(-1);
  ranges.insert(n);
  for(int i = 0; i < n; i++)
  {
    addTree(0, n - 1, 0, i, 1);
  }
  for(int i = 1; i <= n; i++)
  {
    if(inTrash[i])
    {
      it = ranges.upper_bound(pos[i]);
      int r = *it;
      it--;
      int l = *it;
      //int cnt = r - l - 1;
      answer += treeGet(0, n - 1, l + 1, r - 1, 0);
      addTree(0, n - 1, 0, pos[i], 0);
    }
    else
    {
      ranges.insert(pos[i]);
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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