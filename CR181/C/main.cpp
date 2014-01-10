#include <stdio.h>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int a, b, n;
int answer = 0;
__int64 Fact[1000005], Inv[1000005];

bool check(int val)
{
  while(val != 0)
  {
    int current = val % 10;
    if(current != a && current != b)
    {
      return false;
    }
    val /= 10;
  }
  return true;
}

__int64 BinPow(__int64 value, int ex)
{
  if(ex == 0)
    return 1;
  __int64 result;
  result = BinPow(value, ex / 2);
  result = result * result % mod;
  if(ex % 2 == 1)
  {
    return result * value % mod;
  }
  return result;
}

void CalcFactAndInv()
{
  Fact[0] = 1;
  for(int i = 1; i <= n; i++)
  {
    Fact[i] = (Fact[i - 1] * i) % mod;
  }
  Inv[0] = 1;
  for(int i = 1; i <= n; i++)
  {
    Inv[i] = BinPow(Fact[i], mod - 2);
  }
}

__int64 CalcC(int k)
{
  return ((Fact[n] * Inv[k] % mod) * Inv[n - k]) % mod;
}

int main()
{
  scanf("%d %d %d", &a, &b, &n);
  CalcFactAndInv();
  for(int i = 0; i <= n; i++)
  {
    int cntB = n - i;
    if(check(i * a + cntB * b))
    {
      answer += CalcC(i);
      answer %= mod;
    }
  }
  printf("%d", answer);
  return 0;
}
