#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int mod = 1000000007;
char str[110];
int n;

void ReadData()
{
  scanf("%s", &str);
  n = strlen(str);
}

__int64 binPower(int power)
{
  if(power == 0)
    return 1LL;
  
  __int64 result = binPower(power / 2);
  result = (result * result);
  if(power % 2 == 1)
  {
    result *= 2;
  }
  return result % mod;
}

__int64 answer;

void Solve()
{
  answer = 0;
  /*for(int i = 0; i < 100; i++)
  {
    printf("%d\n", binPower(i + 1));
  }*/
  for(int i = 0; i < n; i++)
  {
    if(str[i] == '1')
    {
      answer += binPower(2 * n - i - 2);
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
  //freopen("out.txt", "w", stdout);
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