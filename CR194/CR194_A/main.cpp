#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int l = 1;
  int r = n * n;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n / 2; j++)
    {
      printf("%d %d ", l, r);
      r--;
      l++;
    }
    printf("\n");
  }
  return 0;
}