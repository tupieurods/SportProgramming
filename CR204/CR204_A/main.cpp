#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);
  int a = 0, b = 0;
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    if(val == 0)
    {
      b++;
    }
    else
    {
      a++;
      sum += 5;
    }
  }
  while(a > 0 && (sum % 9) != 0)
  {
    sum -= 5;
    a--;
  }
  if((a == 0 && b == 0)
    || (a != 0 && b == 0))
  {
    printf("-1\n");
  }
  else if(a == 0 && b != 0)
  {
    printf("0\n");
  }
  else
  {
    for(int i = 0; i < a; i++)
    {
      printf("5");
    }
    for(int i = 0; i < b; i++)
    {
      printf("0");
    }
    printf("\n");
  }
  return 0;
}