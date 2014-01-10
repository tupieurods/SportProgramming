#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int TREESIZE = 4 * MAXN;

pair<int, int> segmentTree[TREESIZE];
//first-min, second-max
int k;

void ReadData()
{
  scanf("%d", &k);
}

void update(int index, int value, int pos, int l, int r)
{
  if(l > r)
  {
    throw;
    //return;
  }
  if(l == r)
  {
    segmentTree[index].first = value;
    segmentTree[index].second = value;
    return;
  }
  int cnt = (r - l + 1) / 2;
  int newl = l + cnt;
  int newr = l + cnt - 1;
  if(pos <= newr)
  {
    update(index * 2 + 1, value, pos,  l, newr);
  }
  else
  {
    update(index * 2 + 2, value, pos, newl, r);
  }
  segmentTree[index].first = min(segmentTree[index * 2 + 1].first, segmentTree[index * 2 + 2].first);
  segmentTree[index].second = max(segmentTree[index * 2 + 1].second, segmentTree[index * 2 + 2].second);
}

pair<int, int> defaultVal = make_pair(1000000, -1000000);

pair<int, int> get(int index, int pl, int pr, int l, int r)
{
  if(pl > pr)
  {
    return defaultVal;
  }
  if(pl == l && pr == r)
  {
    return segmentTree[index];
  }
  pair<int, int> result = make_pair(1000000, -1000000);
  int cnt = (r - l + 1) / 2;
  int newl = l + cnt;
  int newr = l + cnt - 1;
  pair<int, int> leftVal = get(index * 2 + 1, pl, min(newr, pr), l, newr);
  pair<int, int> rightVal = get(index * 2 + 2, max(newl, pl), pr, newl, r);
  return make_pair(
    min(leftVal.first, rightVal.first),
    max(leftVal.second, rightVal.second));
}

void Solve()
{
  for(int i = 0; i < TREESIZE; i++)
  {
    segmentTree[i].first = 1000000;
    segmentTree[i].second = -1000000;
  }
  for(int i = 0; i < 100000; i++)
  {
    int n = i + 1;
    int val = (n * 1LL * n) % 12345 + (n * 1LL * n * n) % 23456;
    update(0, val, i + 1, 1, MAXN);
  }
  for(int i = 0; i < k; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x > 0)
    {
      pair<int, int> val = get(0, x, y, 1, MAXN);
      printf("%d\n", val.second - val.first);
    }
    else
    {
      update(0, y, -x, 1, MAXN);
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
  freopen("rvq.in", "r", stdin);
  freopen("rvq.out", "w", stdout);
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