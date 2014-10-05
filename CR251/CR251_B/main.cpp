#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int n, x;
__int64 c[100009];

void ReadData()
{
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &c[i]);
  }
}

__int64 answer;

void Solve()
{
  answer = 0;
  sort(c, c + n);
  for(int i = 0; i < n; i++)
  {
    answer += c[i] * x;
    if(x != 1)
    {
      x--;
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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