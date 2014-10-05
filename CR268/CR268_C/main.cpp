#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;

void ReadData()
{
  scanf("%d", &n);
}

void Solve()
{
  if(n < 4)
  {
    printf("NO\n");
    return;
  }
  if(n == 5)
  {
    printf("YES\n");
    printf("5 - 3 = 2\n");
    printf("2 * 4 = 8\n");
    printf("1 + 2 = 3\n");
    printf("8 * 3 = 24\n");
    return;
  }
  if(n == 4)
  {
    printf("YES\n");
    printf("1 * 4 = 4\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
    return;
  }
  printf("YES\n");
  printf("%d + 1 = %d\n", n - 1, n);
  printf("%d - %d = 0\n", n, n);
  for(int i = 5; i + 1 < n; i++)
  {
    printf("%d * 0 = 0\n", i);
  }
  printf("2 + 0 = 2\n");
  printf("2 * 3 = 6\n");
  printf("6 * 4 = 24\n");
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
    //WriteData();
  }
  return 0;
}