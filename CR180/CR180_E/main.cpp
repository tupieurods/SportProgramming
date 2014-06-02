#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int s[100009], ind[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &s[i]);
    ind[i] = i;
  }
}

int comparer(const void *v1, const void *v2)
{
  return s[*(int*)v1] - s[*(int*)v2];
}

int a[100009], b[100009], ind2[100009];

void Solve()
{
  //Solution idea
  //If we will sort s array, in this case every s[i] >= i, in 0-based
  //it can't be lower, because all s[i] uniq
  //Split a array int three parts: uniq|ToDel|uniq; b array: ToDel|uniq|uniq
  qsort(ind, n, sizeof(int), comparer);
  for(int i = 0; i < n; i++)
  {
    //printf("%d ", s[ind[i]]);
    ind2[ind[i]] = i;
  }
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  int k = (int)ceil(n / 3.0);
  for(int i = 0; i < k; i++)
  {
    a[i] = i;
    b[i] = s[ind[i]] - i;
  }
  for(int i = 0; i < k; i++)
  {
    b[k + i] = i + k;
    a[k + i] = s[ind[k + i]] - i - k;
  }
  for(int i = 2 * k; i < n; i++)
  {
    b[i] = n - 1 - i;
    a[i] = s[ind[i]] - b[i];
  }
}

void WriteData()
{
  printf("YES\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", a[ind2[i]]);
  }
  printf("\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", b[ind2[i]]);
  }
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