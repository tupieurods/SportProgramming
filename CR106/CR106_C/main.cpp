#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

void ReadData()
{
  scanf("%d", &n);
  v.clear();
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    v.push_back(make_pair(val, i + 1));
  }
}

vector<int> xv, yv;

void Solve()
{
  xv.clear();
  yv.clear();
  sort(v.begin(), v.end());
  int cnt = v.size() / 2;
  int s1 = 0, s2 = 0;
  for(int i = 0; i < cnt; i++)
  {
    if(i % 2 == 0)
    {
      s1 += v[i].first;
      s1 += v[n - 1 -i].first;
      xv.push_back(v[i].second);
      xv.push_back(v[n - 1 -i].second);
    }
    else
    {
      s2 += v[i].first;
      s2 += v[n - 1 - i].first;
      yv.push_back(v[i].second);
      yv.push_back(v[n - 1 -i].second);
    }
  }
  if(v.size() % 2 == 1)
  {
    if(abs(s1 + v[cnt].first - s2) <= v[v.size() - 1].first)
    {
      xv.push_back(v[cnt].second);
    }
    else
    {
      yv.push_back(v[cnt].second);
    }
  }
  else
  {
    if(xv.size() > yv.size())
    {
      yv.push_back(xv[xv.size() - 1]);
      xv.pop_back();
    }
    else if(xv.size() < yv.size())
    {
      xv.push_back(yv[yv.size() - 1]);
      yv.pop_back();
    }
  }
}

void WriteData()
{
  printf("%d\n", xv.size());
  for(vector<int>::iterator it = xv.begin(); it != xv.end(); it++)
  {
    printf("%d ", *it);
  }
  printf("\n");
  printf("%d\n", yv.size());
  for(vector<int>::iterator it = yv.begin(); it != yv.end(); it++)
  {
    printf("%d ", *it);
  }
  printf("\n\n");
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