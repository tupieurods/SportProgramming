#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int k, m;
map<int, vector<int>> results[4];

void ReadData()
{
  scanf("%d %d", &k, &m);
}

void Solve()
{
  for(map<int, vector<int>>::iterator it = results[3].begin(); it != results[3].end(); it++)
  {
    for(vector<int>::iterator itS = it->second.begin(); itS != it->second.end(); itS++)
    {
      if(k - *itS >= 10000 || k - *itS < 0)
      {
        continue;
      }
      printf("%04d%04d\n", k - *itS, it->first);
      m--;
      if(m == 0)
      {
        return;
      }
    }
  }
}

void WriteData()
{
  printf("\n");
}

void genResults(int value, int len)
{
  if(len == 1 || results[len - 1].find(value) != results[len - 1].end())
  {
    return;
  }
  results[len - 1][value].push_back(value);
  results[len - 1][value].push_back(-value);
  int divider = 10;
  for(int i = 1; i < len; i++, divider *= 10)
  {
    genResults(value % divider, i);
    genResults(value / divider, len - i);
    vector<int> *s1 = &results[i - 1][value % divider];
    vector<int> *s2 = &results[len - i - 1][value / divider];
    for(vector<int>::iterator it1 = s1->begin(); it1 != s1->end(); it1++)
    {
      for(vector<int>::iterator it2 = s2->begin(); it2 != s2->end(); it2++)
      {
        results[len - 1][value].push_back((*it1) * (*it2));
        results[len - 1][value].push_back((*it1) + (*it2));
      }
    }
  }
  sort(results[len - 1][value].begin(), results[len - 1][value].end());
  results[len - 1][value].resize(distance(results[len - 1][value].begin(), unique(results[len - 1][value].begin(), results[len - 1][value].end())));
}

void generate()
{
  for(int i = 0; i < 10; i++)
  {
    results[0].insert(make_pair(i, vector<int>()));
    results[0][i].push_back(i);
    results[0][i].push_back(-i);
  }
  //printf("phase 1 finished\n");
  for(int i = 0; i < 10000; i++)
  {
    genResults(i, 4);
  }
}

int main()
{
  //freopen("output.txt", "w", stdout);
  generate();
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