#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

__int64 a, b;
const __int64 MOD = 1000000007LL;

void ReadData()
{
  scanf("%I64d %I64d", &a, &b);
}

__int64 answer;

void Solve()
{
  answer = 0;
  for(__int64 i = 1; i <= a; i++)
  {
    answer = (answer + (i * b + 1) % MOD) % MOD;
  }
  /*answer = (((((a * (a + 1)) % MOD) * b) % MOD) / 2LL) % MOD;
  answer = (answer + a) % MOD;*/
  __int64 tmp = ((b * (b - 1)) / 2LL) % MOD;
  answer = (tmp * answer) % MOD;
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
  for(int T = 0; T < QWE;T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}