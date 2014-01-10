#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int a[3009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &a[i]);
  }
}

int comparer(const void *v1, const void *v2)
{
  return *(int*)v1 - *(int*)v2;
}

bool answer;

void Solve()
{
  answer = true;
  qsort(a, m, sizeof(int), comparer);
  if(a[0] == 1 || a[m - 1] == n)
  {
    answer = false;
    return;
  }
  for(int i = 0; i < m; i++)
  {
    if(i < m && i + 1 < m && i + 2 < m
      && (a[i] == a[i + 1] - 1 && a[i] == a[i + 2] - 2))
    {
      answer = false;
      return;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
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