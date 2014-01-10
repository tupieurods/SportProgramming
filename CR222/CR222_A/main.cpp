#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  int a1 = 0, a2 = 0, a3 = 0;
  for(int i = 1; i < 7; i++)
  {
    int d1 = abs(a - i);
    int d2 = abs(b - i);
    if(d1 == d2)
    {
      a2++;
    }
    else if(d1 < d2)
    {
      a1++;
    }
    else
    {
      a3++;
    }
  }
  printf("%d %d %d\n", a1, a2, a3);
  return 0;
}