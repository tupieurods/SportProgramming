#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

struct range
{
  int l, r, value;
};

int n, m;
int a[200000];
vector<range> levels[7009];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < n; i++)
  {
    levels[i].clear();
  }
  #endif
  scanf("%d %d", &n, &m);
}

void add()
{
  int level;
  range current;
  scanf("%d %d %d %d", &level, &current.l, &current.r, &current.value);
  levels[level].push_back(current);
}

int answer[1000001];
int queryNum;

void show()
{
  int level, pos;
  scanf("%d %d", &level, &pos);
  int l = pos, r = pos;
  int cnt = 0;
  for(; level <= n; level++)
  {
    for(vector<range>::iterator it = levels[level].begin(); it != levels[level].end(); it++)
    {
      if(r >= it->l && l <= it->r && answer[it->value] != queryNum)
      {
        cnt++;
        answer[it->value] = queryNum;
      }
    }
    l = a[l];
    r = a[r] + (int)((r & (r - 1)) == 0);
  }
  printf("%d\n", cnt);
}

void Solve()
{
  queryNum = 0;
  for(int T = 0; T < m; T++)
  {
    int queryType;
    scanf("%d", &queryType);
    if(queryType == 1)
    {
      add();
    }
    else if(queryType == 2)
    {
      queryNum++;
      show();
    }
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  int current = 1;
  for(int i = 1; i <= 198000; i++)
  {
    a[i] = current;
    current++;
    if((i & (i - 1)) == 0)
    {
      current++;
    }
  }
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