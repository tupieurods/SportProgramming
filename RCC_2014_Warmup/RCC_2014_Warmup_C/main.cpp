#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k;

void ReadData()
{
  scanf("%d %d", &n, &k);
}

void Solve()
{
  int cnt = n / 2 + n % 2;
  if(k >= cnt)
  {
    printf("-1\n");
    return;
  }
  printf("%d\n", n * k);
  for(int i = 0; i < n; i++)
  {
    int ind = i + 1;
    for(int j = 0; j < k; j++)
    {
      if(ind == n)
      {
        ind = 0;
      }
      printf("%d %d\n", i + 1, ind + 1);
      ind++;
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