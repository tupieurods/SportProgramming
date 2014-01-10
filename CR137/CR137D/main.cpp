#include <stdio.h>
#include <stdlib.h>

int n, x, answer;
int *a, *b;

int compare(const void *a, const void *b)
{
  return (*(int*)b - *(int*)a);
}

void ReadData()
{
  scanf("%d %d", &n, &x);
  a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  b = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
  }
}

void Solve()
{
  answer = 0;
  qsort(a, n, sizeof(int), compare);
  qsort(b, n, sizeof(int), compare);
  int l = 0, r = n - 1;
  while(r >= 0)
  {
    if(a[l] + b[r] >= x)
    {
      answer++;
      l++;
      r--;
    }
    else
    {
      r--;
    }
  }
}

void WriteData()
{
  printf("1 %d\n", answer);
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