#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int compare(const void* a, const void* b)
{
  return (*(int*)b - *(int*)a);
}

int main()
{
  int n, q;
  scanf("%d %d", &n, &q);
  int* data = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &data[i]);
  }
  qsort(data, n, sizeof(int), compare);
  int* b = new int[n + 1];
  memset(b, 0, sizeof(int) * (n + 1));
  for(int i = 0; i < q; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r;
    b[l]++;
    b[r]--;
  }
  int current = 0;
  for(int i = 0; i < n; i++)
  {
    current += b[i];
    b[i] = current;
  }
  qsort(b, n, sizeof(int), compare);
  __int64 result = 0;
  for(int i = 0; i < n; i++)
  {
    result += (__int64)b[i] * (__int64)data[i];
  }
  printf("%I64d\n", result);
  return 0;
}
