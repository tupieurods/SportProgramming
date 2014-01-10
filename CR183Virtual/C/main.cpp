#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  if(n % 2 == 0)
  {
    printf("-1\n");
    return 0;
  }
  for(int i = 0; i < n; i++)
  {
    printf("%d ", i);
  }
  printf("\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", i);
  }
  printf("\n");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", (i + i) % n);
  }
  return 0;
}