#include <stdio.h>
#include <algorithm>

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  for(int i = 0; i < 10000; i++)
  {
    if(a == i)
    {
      printf("yes\n");
      return 0;
    }
    std::swap(a, b);
  }
  printf("no\n");
  return 0;
}