#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

int main()
{
  int n;
  scanf("%d", &n);
  int* data = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &data[i]);
  }
  qsort(data, n, sizeof(int), compare);
  __int64 answer = 0LL;
  for(int i = 0; i < n; i++)
  {
    if(data[i] < 0)
    {
      answer += (__int64)abs(data[i]);
      data[i] = 0;
    }
    answer += (__int64)abs(i + 1 - data[i]);
  }
  printf("%I64d", answer);
  return 0;
}
