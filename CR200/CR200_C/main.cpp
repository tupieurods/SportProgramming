#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Απεδ
__int64 a, b;

void ReadData()
{
  scanf("%I64d %I64d", &a, &b);
}

__int64 answer;

void Solve()
{
  if(b == 1)
  {
    answer = a;
    return;
  }
  answer = (__int64)(ceil((a + b) / 2.0));
}

void WriteData()
{
  printf("%I64d\n", answer);
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