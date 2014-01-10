#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, a[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

__int64 answer;

void Solve()
{
  int maximal = -1;
  __int64 sum = 0;
  for(int i = 0; i < n; i++)
  {
    maximal = std::max(a[i], maximal);
    sum += a[i];
  }
  answer = std::max((__int64)maximal, sum / (n - 1));
  while(answer * (n - 1) < sum)
  {
    answer++;
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