#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#pragma warning(disable: 4996)

int n, v;
int days[3009];

void ReadData()
{
  scanf("%d %d", &n, &v);
  memset(days, 0, sizeof(days));
  for(int i = 0; i < n; i++)
  {
    int day, cnt;
    scanf("%d %d", &day, &cnt);
    days[day] += cnt;
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int day = 1; day < 3009; day++)
  {
    int current = v;
    if(days[day - 1] > 0)
    {
      if(days[day - 1] >= current)
      {
        days[day - 1] -= current;
        current = 0;
      }
      else
      {
        current -= days[day - 1];
        days[day - 1] = 0;
      }
    }
    if(days[day] > 0)
    {
      if(days[day] >= current)
      {
        days[day] -= current;
        current = 0;
      }
      else
      {
        current -= days[day];
        days[day] = 0;
      }
    }
    answer += v - current;
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