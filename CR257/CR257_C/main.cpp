#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

__int64 n, m, k;

void ReadData()
{
  scanf("%I64d %I64d %I64d", &n, &m, &k);
}

__int64 answer;


void Solve()
{
  answer = -1;
  if((n - 1 + m - 1) < k)
  {
    return;
  }
  if(n > m)
  {
    std::swap(n, m);
  }
  for(__int64 i = 1; i * i <= n; i++)
  {
    __int64 j = k + 2 - i;
    if(j >= 1)
    {
      answer = std::max(answer, (n / i) * (m / j));
    }
    j = k + 2 - (n / i);
    if(j >= 1)
    {
      answer = std::max(answer, i * (m / j));
    }
  }
  for(__int64 i = 1; i * i <= m; i++)
  {
    __int64 j = k + 2 - i;
    if(j >= 1)
    {
      answer = std::max(answer, (m / i) * (n / j));
    }
    j = k + 2 - (m / i);
    if(j >= 1)
    {
      answer = std::max(answer, i * (n / j));
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