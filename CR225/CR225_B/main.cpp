#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  printf("%d\n", (m * (m - 1)) / 2);
  for(int i = 0; i < m; i++)
  {
    for(int j = i + 1; j < m; j++)
    {
      if(k == 0)
      {
        printf("%d %d\n", i + 1, j + 1);
      }
      else
      {
        printf("%d %d\n", j + 1, i + 1);
      }
    }
  }
  return 0;
}