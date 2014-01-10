#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__int64 w, m, k;

__int64 S(__int64 val)
{
  __int64 result = 0;
  while(val != 0LL)
  {
    result++;
    val /= 10;
  }
  return result;
}

void ReadData()
{
  scanf("%I64d %I64d %I64d", &w, &m, &k);
}

__int64 answer;

void Solve()
{
  answer = 0;
  __int64 c1 = S(m);
  __int64 n1 = 1LL, n2;
  for(int i = 0; i < c1; i++)
  {
    n1 *= 10LL;
  }
  n2 = n1;
  __int64 cnt = n1 - m;
  __int64 cost = c1 * k;
  if(w / cost >= cnt)
  {
    answer = cnt;
    w -= cost * cnt;
  }
  else
  {
    answer = w / cost;
    return;
  }
  while(true)
  {
    n2 = n1;
    n1 *= 10LL;
    c1++;
    cost += k;
    cnt = n1 - n2;
    if(w / cost >= cnt)
    {
      answer += cnt;
      w -= cost * cnt;
    }
    else
    {
      answer += w / cost;
      return;
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