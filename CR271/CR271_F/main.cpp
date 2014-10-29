#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 100009;

int n;
pair<int, int> tree[4 * MAXN];
vector<pair<int, int>> v;

int gcd(int v1, int v2)
{
  if(v1 == 0)
  {
    return v2;
  }
  return gcd(v2 % v1, v1);
}

void upd(int val, int tl, int tr, int pos, int idx)
{
  if(pos == tl && pos == tr)
  {
    tree[idx].first = tree[idx].second = val;
    return;
  }
  int center = tl + (tr - tl) / 2;
  if(pos <= center)
  {
    upd(val, tl, center, pos, idx * 2);
  }
  else
  {
    upd(val, center + 1, tr, pos, idx * 2 + 1);
  }
  tree[idx].first = min(tree[idx * 2].first, tree[idx * 2 + 1].first);
  tree[idx].second = gcd(tree[idx * 2].second, tree[idx * 2 + 1].second);
}

pair<int, int> nil = make_pair(-1, -1);

pair<int, int> getTreeRange(int tl, int tr, int l, int r, int idx)
{
  if(l > r)
  {
    return nil;
  }
  if(l == tl && r == tr)
  {
    return tree[idx];
  }
  int center = tl + (tr - tl) / 2;
  pair<int, int> p1 = getTreeRange(tl, center, l, min(center, r), idx * 2);
  pair<int, int> p2 = getTreeRange(center + 1, tr, max(center + 1, l), r, idx * 2 + 1);
  if(p1.first == -1)
  {
    return p2;
  }
  else if(p2.first == -1)
  {
    return p1;
  }
  else
  {
    return make_pair(min(p1.first, p2.first), gcd(p1.second, p2.second));
  }
}

void ReadData()
{
  scanf("%d", &n);
  memset(tree, 0, sizeof(tree));
  v.clear();
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    upd(val, 0, n - 1, i, 1);
    v.push_back(make_pair(val, i));
  }
}

void Solve()
{
  sort(v.begin(), v.end());
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    pair<int, int> p = getTreeRange(0, n - 1, l, r, 1);
    if(p.first == p.second)
    {
      int answer = upper_bound(v.begin(), v.end(), make_pair(p.first, r))
        - lower_bound(v.begin(), v.end(), make_pair(p.first, l));
      printf("%d\n", r - l + 1 - answer);
    }
    else
    {
      printf("%d\n", r - l + 1);
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