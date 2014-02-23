#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct elem
{
  int x, y, l;
};

int n, m;
elem vert[50009];
map<int, set<pair<int, int>>> horiz;

void ReadData()
{
#ifndef ONLINE_JUDGE
  horiz.clear();
#endif
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &vert[i].x, &vert[i].y, &vert[i].l);
  }
  for(int i = 0; i < m; i++)
  {
    int xVal, yVal, lVal;
    scanf("%d %d %d", &xVal, &yVal, &lVal);
    horiz[yVal].insert(make_pair(xVal + lVal, xVal));
  }
}

bool between(int l, int r, int value)
{
  return value > l && value < r;
}

int answer;

void Solve()
{
  answer = 0;
  map<int, set<pair<int, int>>>::iterator horizIt;
  set<pair<int, int>>::iterator sIt;
  for(int i = 0; i < n; i++)
  {
    if(vert[i].l <= answer * 2)
    {
      continue;
    }
    horizIt = horiz.lower_bound(vert[i].y);
    for(; horizIt != horiz.end() && horizIt->first < vert[i].y + vert[i].l; horizIt++)
    {
      sIt = horizIt->second.lower_bound(make_pair(vert[i].x, -1));
      for(; sIt != horizIt->second.end() && sIt->second < vert[i].x; sIt++)
      {
        answer = max(answer, min(abs(vert[i].y - horizIt->first),
          min(abs(vert[i].y + vert[i].l - horizIt->first),
          min(abs(sIt->second - vert[i].x), abs(sIt->first - vert[i].x)))));
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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