#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, zeroCnt;
__int64 sum1;

void ReadData()
{
  scanf("%d", &n);
  sum1 = 0;
  zeroCnt = 0;
  for(int i = 0; i < n * 2; i++)
  {
    double val;
    scanf("%lf", &val);
    __int64 val2 = floor(val * 1000.0 + 0.5);
    sum1 += val2 % 1000;
    if(val2 % 1000 == 0)
    {
      zeroCnt++;
    }
  }
}

double answer;

void Solve()
{
  answer = 9999999999.0;
  for(int i = 0; i <= n; i++)
  {
    if(zeroCnt + i < n)
    {
      continue;
    }
    answer = min((__int64)answer, abs(i * 1000 - sum1));
  }
  answer /= 1000.0;
}

void WriteData()
{
  printf("%.3lf\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n2000\n");
    for(int i = 0; i < 4000; i++)
    {
      printf("10000.999 ");
    }
    printf("\n");
    return 0;
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