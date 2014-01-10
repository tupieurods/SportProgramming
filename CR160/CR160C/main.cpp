#include <stdio.h>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

int compare(const void* a, const void* b)
{
  return (*(int*)a - *(int*)b);
}

int main()
{
  int m, n;
  scanf("%d", &m);
  int minimalQ = INT_MAX;
  for(int i = 0; i < m; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    minimalQ = min(minimalQ, tmp);
  }
  scanf("%d", &n);
  int* data = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &data[i]);
  }
  qsort(data, n, sizeof(int), compare);
  int sum = 0;
  /*for(int i = n - 1; i > -1; i--)
  {
    printf("%d\n", data[i]);
  }*/
  int i = n - 1;
  while(i >= 0)
  {
    if(i >= minimalQ)
    {
      for(int j = 0; j < minimalQ; j++)
      {
        sum += data[i];
        i--;
      }
      i -= 2;
    }
    else
    {
      for(int j = 0; j <= i; j++)
      {
        sum += data[j];
      }
      break;
    }
  }
  printf("%d", sum);
  return 0;
}
