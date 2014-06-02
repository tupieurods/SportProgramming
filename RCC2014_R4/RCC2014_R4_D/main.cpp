#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define LOCAL

int n;
bool used[10009];
int parent[10009];

void ReadData()
{
  scanf("%d", &n);
  memset(used, 0, sizeof(used));
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &parent[i]);
  }
}

vector<pair<int, int>> answer;
bool showA;

void Solve()
{
  showA = true;
  answer.clear();
  for(int i = 1; i <= n; i++)
  {
    if(parent[parent[i]] != parent[i])
    {
      showA = false;
      return;
    }
    else if(parent[i] != i)
    {
      if(used[parent[i]] == false)
      {
        used[parent[i]] = true;
        answer.push_back(make_pair(parent[i], i));
      }
      else
      {
        answer.push_back(make_pair(i, parent[i]));
      }
    }
  }
}

void WriteData()
{
  if(showA)
  {
    printf("%d\n", answer.size());
    for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
    {
      printf("%d %d\n", it->first, it->second);
    }
  }
  else
  {
    printf("-1\n");
  }
}

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