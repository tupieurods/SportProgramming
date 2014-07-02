#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, x;
vector<pair<int, int>> v[2];
bool avaible[2][2009];

void ReadData()
{
  v[0].clear();
  v[1].clear();
  memset(avaible, 1, sizeof(avaible));
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; i++)
  {
    int t, h, m;
    scanf("%d %d %d", &t, &h, &m);
    v[t].push_back(make_pair(h, m));
  }
}

int answer;

void Solve()
{
  answer = 0;
  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());
  int current = 0;
  int c[2] = {v[0].size(), v[1].size()};
  int canswer = 0, cx = x;
  while(true)
  {
    if(c[current] == 0)
    {
     break;
    }
    int idx = -1;
    for(int i = 0; i < v[current].size(); i++)
    {
      if(v[current][i].first > cx)
      {
        break;
      }
      if(avaible[current][i] && (idx == -1 || v[current][i].second > v[current][idx].second))
      {
        idx = i;
      }
    }
    if(idx == -1)
    {
      break;
    }
    cx += v[current][idx].second;
    avaible[current][idx] = false;
    c[current]--;
    canswer++;
    current ^= 1;
  }
  answer = max(answer, canswer);
  current = 1;
  c[0] = v[0].size(); c[1] = v[1].size();
  canswer = 0, cx = x;
  memset(avaible, 1, sizeof(avaible));
  while(true)
  {
    if(c[current] == 0)
    {
     break;
    }
    int idx = -1;
    for(int i = 0; i < v[current].size(); i++)
    {
      if(v[current][i].first > cx)
      {
        break;
      }
      if(avaible[current][i] && (idx == -1 || v[current][i].second > v[current][idx].second))
      {
        idx = i;
      }
    }
    if(idx == -1)
    {
      break;
    }
    cx += v[current][idx].second;
    avaible[current][idx] = false;
    c[current]--;
    canswer++;
    current ^= 1;
  }
  answer = max(answer, canswer);
}

void WriteData()
{
  printf("%d\n", answer);
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