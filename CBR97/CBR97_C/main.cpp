#include <stdio.h>
#include <stdlib.h>

int n, a[100009];
int maxInd;

void ReadData()
{
  scanf("%d", &n);
  maxInd = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    if(a[i] > a[maxInd])
    {
      maxInd = i;
    }
  }
}

int compare(const void *v1, const void *v2)
{
  return *(int*)v1 - *(int*)v2;
}

void Solve()
{
  a[maxInd] = a[maxInd] == 1 ? 2 : 1;
  qsort(a, n, sizeof(int), compare);
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
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