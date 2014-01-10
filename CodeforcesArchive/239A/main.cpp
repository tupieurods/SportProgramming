#include <stdio.h>
#include <stdlib.h>

int main()
{
  bool fail = true;
  int y, k, n;
  scanf("%d %d %d", &y, &k, &n);
  int i = k;
  while(i <= n)
  {
    if(i - y > 0)
    {
      printf("%d ", i - y);
      fail = false;
    }
    i += k;
  }
  if(fail)
  {
    printf("-1\n");
  }
  return 0;
}