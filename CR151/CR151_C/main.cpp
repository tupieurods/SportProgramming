#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k;
int a[50], b[50];

int compare(const void *v1, const void *v2)
{
  return (*(int*)v1 - *(int*)v2);
}

void ReadData()
{
  scanf("%d %d", &n, &k);
  memset(a, 0, sizeof(a));
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), compare);
}

void Solve()
{
  int firstEnd = min(n, k);
  for(int i = 0; i < firstEnd; i++)
  {
    printf("1 %d\n", a[i]);
  }
  k -= n;
  int last = 1;
  int rnd = 0;
  for(int i = 0; i < k; i++)
  {
    printf("%d ", last + 1);
    for(int j = 0; j < last; j++)
    {
      printf("%d ", a[n - 1 - j]);
    }
    printf("%d\n", a[rnd]);
    rnd++;
    if(rnd == n - last)
    {
      rnd = 0;
      last++;
    }
  }
}

void WriteData()
{
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