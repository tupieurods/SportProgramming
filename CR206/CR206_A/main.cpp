#include <stdio.h>

int main()
{
  int k, d;
  scanf("%d %d", &k, &d);
  if(d == 0)
  {
    if(k == 1)
    {
      printf("0\n");
    }
    else
    {
      printf("No solution\n");
    }
    return 0;
  }
  printf("%d", d);
  k--;
  for(int i = 0; i < k; i++)
  {
    printf("0");
  }
  printf("\n");
  return 0;
}