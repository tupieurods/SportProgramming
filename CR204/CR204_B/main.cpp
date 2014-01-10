#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> a[100009];
int n;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a[val].push_back(i + 1);
  }
}

vector<pair<int, int>> answer;

void Solve()
{
  for(int i = 1; i < 100001; i++)
  {
    if(a[i].size() == 0)
    {
      continue;
    }
    if(a[i].size() == 1)
    {
      answer.push_back(make_pair(i, 0));
      continue;
    }
    int d = a[i][1] - a[i][0];
    int sz = a[i].size();
    bool flag = true;
    for(int j = 1; j < sz; j++)
    {
      if(a[i][j] - a[i][j - 1] != d)
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      answer.push_back(make_pair(i, d));
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
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
  //scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}