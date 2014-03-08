#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

#define INF 1LL<<60

using namespace std;

int n, m;
__int64 k;
vector<__int64> customK;
__int64 h;
__int64 a[100009];
int c[100009];
bool aVisited[100009];
//map<__int64, int> posToIndex;
map<int, set<__int64>> costToPos;
__int64 D[10009];

void pe()
{
  printf("wtf\n");
  exit(0);
}

void ReadData()
{
  //posToIndex.clear();
  customK.clear();
  costToPos.clear();
  memset(aVisited, 0, sizeof(aVisited));
  scanf("%I64d %d %d %I64d", &h, &n, &m, &k);
  customK.push_back(k);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d %d", &a[i], &c[i]);
    //posToIndex[a[i]] = i;
    if(((a[i] - 1) % k) == 0)
    {
      aVisited[i] = true;
      costToPos[c[i]].insert(i);
    }
  }
  for(int i = 0; i < k; i++)
  {
    D[i] = INF;
  }
  D[1 % k] = 1LL;
}

void Operation_1()
{
  __int64 val;
  scanf("%I64d", &val);
  customK.push_back(val);
  set<pair<__int64, int>> pq;
  pq.insert(make_pair(D[1 % k], 1 % k));
  while(!pq.empty())
  {
    pair<__int64, int> current = *pq.begin();
    pq.erase(pq.begin());
    for(vector<__int64>::iterator it = customK.begin(); it != customK.end(); it++)
    {
      int nxt = (current.first + *it) % k;
      if(D[nxt] > current.first + *it)
      {
        pq.erase(make_pair(D[nxt], nxt));
        D[nxt] = current.first + *it;
        pq.insert(make_pair(D[nxt], nxt));
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(aVisited[i])
    {
      continue;
    }
    if(D[a[i] % k] <= a[i])
    {
      aVisited[i] = true;
      costToPos[c[i]].insert(i);
    }
  }
}

void Operation_2()
{
  int ind, cost;
  scanf("%d %d", &ind, &cost);
  if(cost == 0)
  {
    return;
  }
  ind--;
  if(aVisited[ind])
  {
    int newVal = c[ind] - cost;
    if(costToPos[c[ind]].size() == 1)
    {
      costToPos.erase(c[ind]);
    }
    else
    {
      costToPos[c[ind]].erase(ind);
    }
    c[ind] = newVal;
      costToPos[c[ind]].insert(ind);
  }
  else
  {
    c[ind] -= cost;
  }
}

void Operation_3()
{
  if(costToPos.empty())
  {
    printf("0\n");
    return;
  }
  map<int, set<__int64>>::iterator it = costToPos.end();
  it--;
  printf("%d\n", it->first);
  if(it->second.size() == 1)
  {
    costToPos.erase(it);
  }
  else
  {
    it->second.erase(it->second.begin());
  }
}

void Solve()
{
  for(int i = 0; i < m; i++)
  {
    int operationType;
    scanf("%d", &operationType);
    switch(operationType)
    {
      case 1:
        Operation_1();
        break;
      case 2:
        Operation_2();
        break;
      case 3:
        Operation_3();
        break;
      default:
        throw;
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