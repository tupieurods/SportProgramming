#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int sum, limit;

void ReadData()
{
  scanf("%d %d", &sum, &limit);
}

vector<int> v;
map<int, vector<int>> m;

void Solve()
{
  m.clear();
  v.clear();
  for(int i = 1; i <= limit; i++)
  {
    int res = i & -i;
    m[-res].push_back(i);
  }
  for(map<int, vector<int>>::iterator itM = m.begin(); itM != m.end(); ++itM)
  {
    for(vector<int>::iterator it = itM->second.begin(); it != itM->second.end(); ++it)
    {
      if(sum >= -itM->first)
      {
        sum += itM->first;
        v.push_back(*it);
      }
      if(sum == 0 || sum < itM->first)
      {
        break;
      }
    }
    if(sum == 0)
    {
      break;
    }
  }
  if(sum != 0)
  {
    v.clear();
  }
}

void WriteData()
{
  if(v.size() != 0)
  {
    printf("%d\n", v.size());
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
      printf("%d ", *it);
    }
    printf("\n");
  }
  else
  {
    printf("-1\n");
  }
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