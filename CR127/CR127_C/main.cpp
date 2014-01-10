#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  if(n == 1)
  {
    printf("1\n");
    return 0;
  }
  if(n == 2)
  {
    printf("3\n");
    return 0;
  }
  if(n == 3)
  {
    printf("5\n");
    return 0;
  }
  if(n == 4 || n == 5)
  {
    printf("3\n");
    return 0;
  }
  for(int i = 5; i < 101; i++)
  {
    if(i % 2 == 0)
      continue;
    int maximal = i * (i / 2) + (i / 2) + 1;
    if(maximal >= n)
    {
      printf("%d", i);
      return 0;
    }
  }
  printf("wtf\n");
  return 0;
}