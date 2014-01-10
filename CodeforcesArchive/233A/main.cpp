#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);
  if(n % 2 == 1)
  {
    printf("-1\n");
    return 0;
  }
  for(int i = 1; i <= n; i++)
  {
    int val = i % 2 == 1 ? i + 1 : i - 1;
    printf("%d ", val);
  }
  printf("\n");
  return 0;
}