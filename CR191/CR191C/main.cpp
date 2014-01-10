#include <stdio.h>
#include <string.h>

char str[100005];
__int64 k;
const int mod = 1000000007;

void ReadData()
{
  scanf("%s", &str);
  scanf("%I64d%*c", &k);
}

__int64 binPow(__int64 power, __int64 val)
{
  if(power == 0)
    return 1;
  __int64 result = binPow(power / 2, val) % mod;
  result = (result * result) % mod;
  if(power % 2 == 1)
  {
    result = (result * val) % mod;
  }
  return result % mod;
}

__int64 answer;

void Solve()
{
  answer = 0LL;
  __int64 len = strlen(str);
  __int64 s = binPow(k * len, 2) - 1;
  __int64 divider = binPow(mod - 2, binPow(len, 2) - 1);
  s = s * divider % mod;
  for(int i = len - 1; i >= 0; i--)
  {
    if(str[i] == '5' || str[i] == '0')
    {
      answer += (binPow(i, 2) * s) % mod;
      answer %= mod;
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}