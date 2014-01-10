#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int a[10];
  memset(a, 0, sizeof(a));
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a[val]++;
    if(val == 7 || val == 5)
    {
      printf("-1\n");
      return 0;
    }
  }
  if(n / 3 != a[1] || a[3] > a[6])
  {
    printf("-1\n");
    return 0;
  }
  int cnt = n / 3;
  a[6] -= a[3];
  if(a[6] + a[4] != a[2])
  {
    printf("-1\n");
    return 0;
  }
  for(int i = 0; i < a[3]; i++)
  {
    printf("1 3 6\n");
  }
  for(int i = 0; i < a[4]; i++)
  {
    printf("1 2 4\n");
  }
  for(int i = 0; i < a[6]; i++)
  {
    printf("1 2 6\n");
  }
  return 0;
}