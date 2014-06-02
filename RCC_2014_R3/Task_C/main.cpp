#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;

void ReadData()
{
  scanf("%d", &n);
}

vector<pair<int, int>> answer;

void Solve()
{
  for(int i = 2; i <= n; i++)
  {
    answer.push_back(make_pair(1, i));
  }
  int start = 2;
  while(start < n)
  {
    answer.push_back(make_pair(start, start + 1));
    start += 2;
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d %d\n", it->first, it->second);
  }
}

//#define LOCAL

int main()
{
  int QWE = 1;
  #ifdef LOCAL
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