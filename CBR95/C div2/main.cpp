#include <stdio.h>
#include <string.h>

using namespace std;

__int64 treg[32][32];

__int64 CalcC(__int64 n, __int64 k)
{
  if(n < k)
    throw;
  if((k == 0) || (n == k))
  {
    return 1;
  }
  __int64 from, second = 2LL;
  if(n - k > k)
  {
    from = n - k + 1;
  }
  else
  {
    from = k + 1;
    k = n - k;
  }
  __int64 result = 1LL;
  for(__int64 i = from; i <= n; i++)
  {
    result *= i;
    while(second <= k && result % second == 0)
    {
      result /= second;
      second++;
    }
  }
  while(second <= k && result % second == 0)
  {
    result /= second;
    second++;
  }
  return result;
}

void CalcTreg(int current, int maximal)
{
  treg[current][1] = 1;
  treg[current][current] = 1;
  for(int i = 2; i < current; i++)
  {
    treg[current][i] = treg[current - 1][i] + treg[current - 1][i - 1];
  }
  if(current != maximal)
    CalcTreg(current + 1, maximal);
}

__int64 CalcC2(__int64 n, __int64 k)
{
  //printf("n: %I64d k: %I64d\n", n, k);
  return treg[n + 1][k + 1];
}

int main()
{
  memset(treg, 0, sizeof(treg));
  treg[0][0] = 1;
  CalcTreg(1, 31);
  /*for(int i = 1; i <= 10; i++)
  {
    for(int j = 1; j <=i; j++)
    {
      printf("%I64d ", treg[i][j]);
    }
    printf("\n");
  }*/
  __int64 n, m, t;
  scanf("%I64d %I64d %I64d", &n, &m, &t);
  __int64 answer = 0LL;
  for(__int64 i = 4; i <= n; i++)
  {
    if(t - i <= 0LL)
      break;
    if(t - i > m)
      continue;
    answer += CalcC2(n, i) * CalcC2(m, t - i);
    //printf("%I64d %I64d\n", CalcC2(n, i), CalcC2(m, t - i));
    //printf("%I64d %I64d\n", CalcC(n, i), CalcC(m, t - i));
  }
  printf("%I64d", answer);
  return 0;
}
