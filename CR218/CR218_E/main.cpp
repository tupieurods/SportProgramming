#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k;
int id[300009], a[300009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    id[i] = i;
  }
  scanf("%d", &k);
}

int compare(const void *v1, const void *v2)
{
  return a[*(int*)v1] - a[*(int*)v2];
}

int answer;

void Solve()
{
  qsort(id, n, sizeof(int), compare);
  answer = 0;
  int sum = 0;
  for(int i = 1; i < k; i++)
  {
    sum += std::abs(a[id[i]] - a[id[i - 1]]);
  }
  int sumBest = sum;
  int cnt = n - k + 1;
  for(int i = 1; i < cnt; i++)
  {
    sum -= std::abs(a[id[i]] - a[id[i - 1]]);
    sum += std::abs(a[id[i + k - 2]] - a[id[k + i - 1]]);
    if(sum < sumBest)
    {
      sumBest = sum;
      answer = i;
    }
  }
  /*for(int i = 0; i < n; i++)
  {
    printf("%d ", a[id[i]]);
  }*/
  printf("%d\n", sumBest);
}

void WriteData()
{
  for(int i = 0; i < k; i++)
  {
    printf("%d ", id[answer + i] + 1);
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