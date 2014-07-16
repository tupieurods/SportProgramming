#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;
vector<pair<int, int>> sectors;

void Solve()
{
  int l = 0, r = 0;
  answer = 0;
  a[n] = -1;
  sectors.clear();
  for(int i = 0; i < n; i++)
  {
    if(a[i] >= a[i + 1])
    {
      sectors.push_back(make_pair(l, r));
      l = i + 1;
      r = i + 1;
    }
    else
    {
      r++;
    }
  }
  //printf("stage1\n");
  int cnt = sectors.size();
  for(int i = 0; i < cnt; i++)
  {
    if(i == cnt - 1)
    {
      answer = max(answer, sectors[i].second - sectors[i].first + 1);
      break;
    }
    pair<int, int> s1 = sectors[i];
    pair<int, int> s2 = sectors[i + 1];
    if(s2.first == s2.second)
    {
      answer = max(answer, s2.second - s1.first + 1);
    }
    else if(s1.first == s1.second)
    {
      /*if(a[s2.first] > 1 || a[s2.first + 1] > 2)
      {*/
      answer = max(answer, s2.second - s1.first + 1);
      //}
    }
    else if(a[s2.first + 1] - a[s1.second - 1] > 2 && (a[s2.first + 1] - a[s1.second] > 1 || a[s2.first] - a[s1.second - 1] > 1))
    {
      answer = max(answer, s2.second - s1.first + 1);
    }
    else
    {
      answer = max(answer, max(s2.second - s2.first + 1, s1.second - s1.first + 1) + 1);
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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