#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int i = 1;
  while(i <= m && i <= n)
  {
    m -= i;
    i %= n;
    i++;
  }
  printf("%d\n", m);
  return 0;
}