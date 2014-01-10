#include <stdio.h>
#include <algorithm>
#include <time.h>
//TL, I'm choosing you
__int64 answer;
__int64 x, y, m;

void ReadData()
{
  scanf("%I64d %I64d %I64d", &x, &y, &m);
}

__int64 abs64(__int64 val)
{
  return val >= 0LL ? val : -val;
}

void Solve()
{
  answer = 0LL;
  if(x >= m || y >= m)
    return;
  if((x <= 0 && y <= 0))
  {
    answer = -1LL;
    return;
  }
  if(x > y)
    std::swap(x, y);
  if(x < 0)
  {
    answer = abs64(x - std::min(0LL, m)) / y;
    x += y * answer;
  }
  while(true)
  {
    if(x >= m || y >= m)
      return;
    __int64 d1 = abs64(x - m);
    __int64 d2 = abs64(y - m);
    if(d1 < d2)
    {
      y = x + y;
    }
    else
    {
      x = x + y;
    }
    answer++;
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