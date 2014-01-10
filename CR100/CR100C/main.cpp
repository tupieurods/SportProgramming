#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, *r;
vector<pair<int, int>> v;
map<int, int, greater<int>> m;
map<int, int, greater<int>>::iterator it;

void ReadData()
{
  scanf("%d", &n);
  r = new int[n];
  m.clear();
  it = m.begin();
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    it = m.find(val);
    if(it != m.end())
      it->second++;
    m.insert(make_pair(val, 1));
  }
}

vector<pair<int, pair<int,int>>> answer;
pair<int, int> a[3];

void Solve()
{
  priority_queue<pair<int, int>> q;
  for(it = m.begin(); it != m.end(); it++)
  {
    q.push(make_pair(it->second, it->first));
  }
  while(q.size() >= 3)
  {
    for(int i = 0; i < 3; i++)
    {
      a[i] = q.top();
      swap(a[i].first, a[i].second);
      q.pop();
    }
    sort(a, a + 3);
    answer.push_back(make_pair(a[2].first, make_pair(a[1].first, a[0].first)));
    for(int i = 0; i < 3; i++)
    {
      if(a[i].second > 1)
      q.push(make_pair(a[i].second - 1, a[i].first));
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(int i = 0; i < answer.size(); i++)
  {
    printf("%d %d %d\n", answer[i].first, answer[i].second.first, answer[i].second.second);
  }
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