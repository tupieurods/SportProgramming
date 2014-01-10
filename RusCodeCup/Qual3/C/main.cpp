#include <stdio.h>
#include <stdlib.h>

int n;
int a[1000005];
int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

void ReadData()
{
  scanf("%d", &n);
  //a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), compare);
}

__int64 answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < n / 2; i++)
  {
    answer -= a[i];
  }

  for(int i = n / 2; i < n; i++)
  {
    answer += a[i];
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
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}