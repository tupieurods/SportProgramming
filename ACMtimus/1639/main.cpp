#include <stdio.h>

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  m *= n;
  if(m % 2 == 0)
    printf("[:=[first]\n");
  else
    printf("[second]=:]\n");
  return 0;
}