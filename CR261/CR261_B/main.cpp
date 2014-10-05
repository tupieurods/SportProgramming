#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

int n, minimal, maximal;
map<int, int> m;

void ReadData()
{
  m.clear();
  minimal = INT_MAX;
  maximal = INT_MIN;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    minimal = min(minimal, val);
    maximal = max(maximal, val);
    m[val]++;
  }
}

__int64 answer;

void Solve()
{
  answer = 0;
  if(minimal == maximal)
  {
    __int64 val = (m.begin())->second;
    answer = (val * (val - 1LL)) / 2LL;
    return;
  }
  map<int, int>::iterator it2;
  for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
  {
    it2 = m.find(it->first + (maximal - minimal));
    if(it2 != m.end())
    {
      answer += it->second * 1LL * it2->second;
    }
  }
}

void WriteData()
{
  printf("%d %I64d\n", maximal - minimal, answer);
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