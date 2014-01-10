#include <stdio.h>
#include <stdlib.h>

using namespace std;

__int64* data;
int n;

int compare(const void* a, const void* b)
{
  return (*(__int64*)b - *(__int64*)a);
}

__int64 GetSum(__int64 start, __int64 end)
{
  if(end >= n)
    return GetSum(start, n - 1);
  return data[end] - data[start-1];
}

__int64 GetAnwser(int k)
{
  __int64 currentSum = 0;
  __int64 level = 1;
  __int64 len = 1;
  for(__int64 j = 1; j < n; j += len)
  {
    len *= k;
    currentSum += level * GetSum(j, j + len - 1);
    //printf("gS=%d\nj=%d\nj+len=%d\n", GetSum(j, j + len), j, j + len);
    level++;
  }
  return currentSum;
}__int64

int main()
{
  scanf("%d", &n);
  data = new __int64[n];
  for(int i = 0; i < n; i++)
    scanf("%I64d", &data[i]);
  qsort(data, n, sizeof(__int64), compare);

  __int64 tmp = 0;
  for(int i = 0; i < n; i++)
  {
    tmp += data[i];
    data[i] = tmp;
  }

  int q;
  scanf("%d", &q);
  int k;
  __int64 k1 = GetAnwser(1);
  for(int i = 0; i < q; i++)
  {
    scanf("%d", &k);
    if(k == 1)
    {
      printf("%I64d ", k1);
      continue;
    }
    printf("%I64d ", GetAnwser(k));
  }

  return 0;
}
