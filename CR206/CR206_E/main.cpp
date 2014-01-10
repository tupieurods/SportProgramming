#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k, minimal, maximal;
int a[300009], sums[1000009];

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

void ReadData()
{
  scanf("%d %d", &n, &k);
  minimal = 1000009;
  maximal = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    minimal = min(minimal, a[i]);
    maximal = max(maximal, a[i]);
  }
}

int getSum(int l, int r)
{
  int l_v = sums[min(1000008, l - 1)];
  int r_v = sums[min(1000008, r)];
  return r_v - l_v;
}

int answer;

int compare(const void *v1, const void *v2)
{
  return *(int*)v1 - *(int*)v2;
}

void Solve()
{
  if(minimal <= k + 1)
  {
    answer = minimal;
    return;
  }
  answer = 1;
  memset(sums, 0, sizeof(sums));
  qsort(a, n, sizeof(int), compare);
  int index = 0;
  for(int i = 1; i < 1000009; i++)
  {
    sums[i] = sums[i - 1];
    while(index < n && a[index] == i)
    {
      sums[i]++;
      index++;
    }
  }
  for(int i = k + 1; i <= minimal; i++)
  {
    int p = maximal / i;
    int check = 0;
    for(int j = 1; j <= p; j++)
    {
      check += getSum(j * i, j * i + k);
    }
    if(check == n)
    {
      answer = i;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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