#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

bool swapped;
__int64 n, a, b;

void ReadData()
{
  scanf("%I64d %I64d %I64d", &n, &a, &b);
  swapped = false;
  if(a > b)
  {
    swapped = true;
    std::swap(a, b);
  }
}

__int64 answer[3];

void Solve()
{
  if(a * b >= 6LL * n)
  {
    answer[0] = a * b;
    answer[1] = a;
    answer[2] = b;
  }
  else
  {
    __int64 total = 6LL * n;
    __int64 r = sqrt((double)total);
    while(r * r < total)
    {
      r++;
    }
    answer[0] = -1;
    for(__int64 newA = a; newA <= r; newA++)
    {
      __int64 newB = total / newA;
      if(total % newA != 0)
      {
        newB++;
      }
      if(b <= newB)
      {
        __int64 c = newA * newB;
        if((answer[0] == -1 || c <= answer[0]) && c >= total)
        {
          answer[0] = c;
          answer[1] = newA;
          answer[2] = newB;
        }
      }
    }
  }
  if(swapped)
  {
    std::swap(answer[1], answer[2]);
  }
}

void WriteData()
{
  printf("%I64d\n%I64d %I64d\n", answer[0], answer[1], answer[2]);
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