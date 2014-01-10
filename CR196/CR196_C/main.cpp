#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n, m, k;
const __int64 MOD = 1000000009;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
}

__int64 answer;

__int64 binPow(int v, int power)
{
  if(power == 0)
  {
    return 1LL;
  }
  __int64 tmp = binPow(v, power / 2) % MOD;
  tmp = tmp * tmp % MOD;
  if(power % 2 == 1)
  {
    tmp *= v;
    tmp %= MOD;
  }
  return tmp;
}

void Solve()
{
  int x = max(0, m - (n - n % k) / k * (k - 1) - n % k);
  answer = ((binPow(2, x + 1) - 2) * k % MOD + m - x * k) % MOD;
  if(answer < 0)
  {
    answer += MOD;
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