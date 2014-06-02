#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int cnt;

void ReadData()
{
  scanf("%d", &cnt);
}

void Solve()
{
  for(int T = 0; T < cnt; T++)
  {
    int n, k;
    scanf("%d %d", &n, &k);
    int height = 0;
    while(n > 1 && n % 2 != 0)
    {
      n /= 2;
      height++;
    }

  }
}

void WriteData()
{
  printf("\n");
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