#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
__int64 k;

void ReadData()
{
  scanf("%d %d %I64d", &n, &m, &k);
}

__int64 answer;

void Solve()
{
  answer = n * 1LL * m + 9;
  __int64 l = 1;
  __int64 r = n * 1LL * m + 9;
  while(r > l)
  {
    __int64 mid = (r + l) / 2LL;
    __int64 cnt = 0;
    for(int i = 1; i <= n; i++)
    {
      cnt += std::min(mid / i, m * 1LL);
    }
    if(cnt >= k)
    {
      r = mid;
    }
    else
    {
      l = mid + 1;
    }
  }
  answer = r;
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