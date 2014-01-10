#include <stdio.h>
#include <stdlib.h>

__int64 n, k, answer;

void ReadData()
{
  scanf("%I64d %I64d", &n, &k);
}

__int64 fact(__int64 v)
{
  __int64 result = 1LL;
  for(__int64 i = 2LL; i <= v; i++)
  {
    result *= i;
  }
  return result;
}

__int64 calcP(__int64 N, __int64 K)
{
  __int64 result = 1;
  result = fact(N);
  result = result / (fact(N - K));
  return result;
}

__int64 calcC(__int64 N, __int64 K)
{
  __int64 result = 1;
  result = fact(N);
  result = result / (fact(K) * fact(N - K));
  return result;
}

void Solve()
{
  answer = 0;
  if(k > n)
  {
    answer = 0;
    return;
  }
  if(k == n)
  {
    answer = fact(n);
    return;
  }
  if(k == 0)
  {
    answer = 1;
    return;
  }
  if(k == 1)
  {
    answer = n * n;
    return;
  }
  /*for(int i = 1; i <= n - k + 1; i++)
  {
    //printf("C %I64d_%I64d = %I64d\n", n - i, k - 1, calcC(n - i, k - 1));
    answer += n * calcC(n - i, k - 1) * (n - 1) * (k - 1);
  }*/
  answer = (fact(n) / fact(n - k)) * (fact(n) / fact(n - k)) / fact(k);
  //answer *= 2LL;
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
  //printf("%I64d", 4*calcC(6,3)*calcC(9,6));
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}