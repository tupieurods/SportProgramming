#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int a[109];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int delta;
vector<pair<int, int>> answer;

void Solve()
{
  answer.clear();
  if(n == 1)
  {
    delta = 0;
    return;
  }
  delta = INT_MAX;
  while(k != 0)
  {
    k--;
    int minimal = 0;
    for(int i = 1; i < n; i++)
    {
      if(a[i] < a[minimal])
      {
        minimal = i;
      }
    }
    int maximal = minimal == 0 ? 1 : 0;
    for(int i = 1; i < n; i++)
    {
      if(a[i] > a[maximal])
      {
        maximal = i;
      }
    }
    if(a[minimal] == a[maximal])
    {
      delta = 0;
      break;
    }
    a[minimal]++;
    a[maximal]--;
    answer.push_back(make_pair(maximal + 1, minimal + 1));
    for(int i = 0; i < n; i++)
    {
      if(a[i] < a[minimal])
      {
        minimal = i;
      }
      if(a[i] > a[maximal])
      {
        maximal = i;
      }
    }
    delta = a[maximal] - a[minimal];
    if(delta == 0)
    {
      break;
    }
  }
}

void WriteData()
{
  printf("%d %d\n", delta, answer.size());
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); ++it)
  {
    printf("%d %d\n", it->first, it->second);
  }
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