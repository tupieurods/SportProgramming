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

void treeAdd(int pos, int val)
{
  while(pos <= n)
  {
    tree[pos] += val;
    pos += (pos & -pos);
  }
}

int getSum(int pos)
{
  int answer = 0;
  while(pos > 0)
  {
    answer += tree[pos];
    pos -= (pos & -pos);
  }
  return answer;
}

void Solve()
{
  answer = 0;
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
    l[i] = cnt[a[i]];
    treeAdd(l[i], 1);
  }
  memset(cnt, 0, sizeof(cnt));
  for(int i = n - 1; i >= 0; i--)
  {
    treeAdd(l[i], -1);
    cnt[a[i]]++;
    //r[i] = cnt[a[i]];
    answer += getSum(n) - getSum(cnt[a[i]]);
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