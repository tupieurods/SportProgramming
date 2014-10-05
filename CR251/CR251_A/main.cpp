#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable: 4996)

int n, d;

void ReadData()
{
  scanf("%d %d", &n, &d);
}

int answer;

void Solve()
{
  int sum = (n - 1) * 10;
  answer = 2 * (n - 1);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    sum += val;
  }
  d -= sum;
  if(d < 0)
  {
    answer = -1;
    return;
  }
  answer += d / 5;
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