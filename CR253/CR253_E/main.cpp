#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n;
vector<pair<int, int>> v;
map<int, int> m;

void ReadData()
{
  scanf("%d", &n);
  v.clear();
  m.clear();
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    v.push_back(make_pair(val, i));
    m[i] = val;
  }
}

__int64 answer;

void Solve()
{
  answer = 0;
  sort(v.begin(), v.end());
  int cnt = n;
  map<int, int>::iterator itm;
  for(vector<pair<int, int>>::iterator it = v.begin(); it != v.end() && m.size() > 2; ++it)
  {
    itm = m.find(it->second);
    if(itm != m.begin() && itm != --m.end())
    {
      answer += min(prev(itm)->second, next(itm)->second);
    }
    else
    {
      answer += it->first;
    }
    m.erase(itm);
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