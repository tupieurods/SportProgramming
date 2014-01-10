#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>

__int64 n;

void ReadData()
{
  scanf("%I64d", &n);
}

__int64 ans1, ans2;

void Solve()
{
  ans1 = _I64_MAX;
  //Остался столб, две спереди, две справа и один верхний слой спёрли
  ans2 = (n + 1) * 3 *3 - n;
  for(__int64 A = 1; A * A * A <= n; A++)
  {
    if(n % A != 0)
      continue;
    for(__int64 B = A; B * B <= n / A; B++)
    {
      __int64 r = A * B;
      if(n % r == 0)
      {
        __int64 C = n / (A * B);
        r = (A + 1) * (B + 2) * (C + 2);
        ans1 = std::min(ans1, r - n);
        //ans2 = std::max(ans2, r - n);
      }
    }
  }
}

void WriteData()
{
  printf("%I64d %I64d\n", ans1, ans2);
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