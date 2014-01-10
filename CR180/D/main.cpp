#include <stdio.h>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

int main()
{
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if(n > m)
  {
    printf("YES");
    return 0;
  }
  int *a = new int[n], *b = new int[m];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }
  qsort(a, n, sizeof(int), compare);
  qsort(b, m, sizeof(int), compare);
  n--;
  m--;
  while(n > -1 && m > -1)
  {
    if(a[n] > b[m])
    {
      printf("YES");
      return 0;
    }
    n--;
    m--;
  }
  if(n > m)
  {
    printf("YES");
  }
  else
  {
    printf("NO");
  }
  return 0;
}
