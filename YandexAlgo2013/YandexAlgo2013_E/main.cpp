#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <inttypes.h>

//#define LOCAL
#define __int64 int64_t

int n, x, k;
int arr[100009];

void ReadData()
{
  scanf("%d %d %d", &n, &x, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
}

int compare(const void *a, const void *b)
{
  return (*(int*)a - *(int*)b);
}

__int64 answer;

void Solve()
{
  answer = 0LL;
  if(x == 1)
  {
    k++;
    x = 0;
  }
  if(x == 0)
  {
    for(int i = 0; i < n; i++)
    {
      answer += arr[i];
    }
    answer = (answer / k) + (__int64)(answer % k != 0);
    return;
  }
  __int64 unsolved = 0LL;
  for(int i = 0; i < n; i++)
  {
    unsolved += arr[i];
    answer += arr[i] / x;
    arr[i] = arr[i] % x;
  }
  if(unsolved <= answer * (x + k))
  {
    answer = (unsolved / (x + k)) + (__int64)(unsolved % (x + k) != 0);
    return;
  }
  qsort(arr, n, sizeof(int), compare);
  unsolved -= answer * (x + k);
  for(int i = n - 1; i >= 0; i--)
  {
    answer++;
    unsolved -= arr[i] + k;
    if(unsolved <= 0LL)
      return;
  }
}

void WriteData()
{
  printf("%lld\n", answer);
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
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