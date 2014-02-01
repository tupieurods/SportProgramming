#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  printf("%d\n", n % 2 == 0 ? (n * n) / 2 : (n * n) / 2 + 1);
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(i % 2 == 1)
      {
        printf("%c", j % 2 == 1 ? 'C' : '.');
      }
      else
      {
        printf("%c", j % 2 == 0 ? 'C' : '.');
      }
    }
    printf("\n");
  }
  return 0;
}