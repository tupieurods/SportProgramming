#include <stdio.h>

int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", max(120 + (b - 40) * 2, 119 + (a - 40) * 2));
  return 0;
}