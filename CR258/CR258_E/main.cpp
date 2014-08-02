#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable:4996)

int n;
__int64 s;
__int64 f[29];
const __int64 MOD = 1000000007;
__int64 fact[29], inv[29];

void ReadData()
{
  scanf("%d %I64d", &n, &s);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &f[i]);
  }
}

__int64 answer;

__int64 getC(__int64 _n, __int64 _k)
{
  if(_k < 0 || _n < 0)
  {
    return 0;
  }
  __int64 answer = 1;
  for(__int64 i = _n - _k + 1; i <= _n; i++)
  {
    answer = (answer * (i % MOD)) % MOD;
  }
  return (answer * inv[_k]) % MOD;
}

void Solve()
{
  answer = getC(s + n - 1, n - 1);
  //answer = 0;
  int cnt = 1 << n;
  for(int mask = 1; mask < cnt; mask++)
  {
    int cnt = 0;
    __int64 copyS = s;
    int copyMask = mask;
    for(int i = 0; i < 20; i++)
    {
      if((copyMask & 1) != 0)
      {
        copyS -= f[i] + 1;
        cnt++;
      }
      copyMask >>= 1;
    }
    if(copyS < 0)
    {
      continue;
    }
    __int64 adder = getC(copyS + n - 1, n - 1);
    //printf("%I64d\n", -adder * (cnt % 2 == 1 ? 1 : -1));
    answer = answer - adder * (cnt % 2 == 1 ? 1 : -1);
    //printf("%I64d\n", answer);
    while(answer < 0)
    {
      answer += MOD;
    }
    answer %= MOD;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

__int64 binPow(__int64 val, int power)
{
  if(power == 0)
  {
    return 1LL;
  }
  __int64 result = binPow(val, power / 2);
  result = (result * result) % MOD;
  return power % 2 == 0 ? result : (result * val) % MOD;
}

int main()
{
  fact[0] = fact[1] = 1;
  inv[0] = inv[1] = 1;
  for(int i = 2; i < 29; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = binPow(fact[i], MOD - 2);
  }
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