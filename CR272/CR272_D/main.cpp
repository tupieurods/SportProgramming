#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k;

void ReadData()
{
  scanf("%d %d", &n, &k);
}

int adders[4] = {1, 2, 3, 5};

void Solve()
{
  printf("%d\n", (6 * n - 1) * k);//equals to last element 6 * (n - 1) + 5
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      printf("%d ", (6 * i + adders[j]) * k);
    }
    printf("\n");
  }
}

void WriteData()
{
  printf("\n");
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