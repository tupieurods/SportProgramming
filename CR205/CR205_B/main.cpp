#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <deque>

using namespace std;

int n, a[209], b[209];
int cnt, s1cnt, s2cnt;

deque<int> shit[100];

void ReadData()
{
#ifndef ONLINE_JUDGE
  for(int i = 0; i < 100; i++)
  {
    shit[i].clear();
  }
#endif
  scanf("%d", &n);
  cnt = 2 * n;
  for(int i = 0; i < cnt; i++)
  {
    scanf("%d", &a[i]);
    shit[a[i]].push_back(i);
    b[i] = 1;
  }
}

int answer;

void Solve()
{
  set<int> s1, s2;
  bool flag = true;
  int s2cnt = 0;
  for(int i = 10; i < 100; i++)
  {
    if(s2cnt == n)
    {
      break;
    }
    if(shit[i].size() != 1)
    {
      continue;
    }
    if(flag)
    {
      s1.insert(a[shit[i][0]]);
    }
    else
    {
      s2.insert(a[shit[i][0]]);
      s2cnt++;
      b[shit[i][0]] = 2;
    }
    shit[i].pop_back();
    flag = !flag;
  }
  for(int i = 10; i < 100; i++)
  {
    if(s2cnt == n)
    {
      break;
    }
    if(shit[i].size() < 2)
    {
      continue;
    }
    s1.insert(a[shit[i][0]]);
    s2.insert(a[shit[i][1]]);
    s2cnt++;
    b[shit[i][1]] = 2;
    shit[i].pop_front();
    shit[i].pop_front();
  }
  for(int i = 10; i < 100; i++)
  {
    if(s2cnt == n)
    {
      break;
    }
    if(shit[i].size() == 0)
    {
      continue;
    }
    while(true)
    {
      if(s2cnt == n || shit[i].size() == 0)
      {
        break;
      }
      b[shit[i][0]] = 2;
      shit[i].pop_front();
      s2cnt++;
    }
  }
  for(int i = 10; i < 100; i++)
  {
    if(shit[i].size() != 0)
    {
      s1.insert(a[shit[i][0]]);
    }
  }
  answer = s1.size() * s2.size();
}

void WriteData()
{
  printf("%d\n", answer);
  for(int i = 0; i < cnt; i++)
  {
    printf("%d ", b[i]);
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