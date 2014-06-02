#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MOD 1000000007

int n;
char str[2][100009];

void ReadData()
{
  scanf("%d%*c", &n);
  scanf("%s%*c", str[0]);
  scanf("%s%*c", str[1]);
}

__int64 binPow(int value, int power)
{
  if(power == 0)
  {
    return 1LL;
  }
  __int64 result = binPow(value, power / 2);
  result = (result * result) % MOD;
  return ((power % 2) == 1) ? (result * value) % MOD : result;
}

__int64 answer;

void Solve()
{
  int power = 0;
  __int64 lower_equal = 1;
  __int64 higher_equal = 1;
  __int64 equal = 1;
  for(int i = 0; i < n; i++)
  {
    if(str[0][i] == '?' && str[1][i] == '?')
    {
      power += 2;
      lower_equal = (lower_equal * 55) % MOD;
      higher_equal = (higher_equal * 55) % MOD;
      equal = (equal * 10) % MOD;
    }
    else if(str[0][i] != '?' && str[1][i] != '?')
    {
      if(str[0][i] < str[1][i])
      {
        equal = 0;
        higher_equal = 0;
      }
      else if(str[0][i] > str[1][i])
      {
        lower_equal = 0;
        equal = 0;
      }
    }
    else
    {
      power++;
      if(str[0][i] == '?')
      {
        lower_equal = (lower_equal * ((int)(str[1][i] - '0') + 1)) % MOD;
        higher_equal = (higher_equal * (10 - (int)(str[1][i] - '0'))) % MOD;
      }
      else
      {
        lower_equal = (lower_equal * (10 - (int)(str[0][i] - '0'))) % MOD;
        higher_equal = (higher_equal * ((int)(str[0][i] - '0') + 1)) % MOD;
      }
    }
  }
  answer = (binPow(10, power) - lower_equal - higher_equal + equal) % MOD;
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
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
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