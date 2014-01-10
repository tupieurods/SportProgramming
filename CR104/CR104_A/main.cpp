#include <stdio.h>

int main()
{
  int n;
  scanf("%d%*c", &n);
  char str[59];
  scanf("%s", str);
  int c = n / 2 + 1;
  int a[2] = {0, 0};
  int index = 0;
  for(int i = 1; i <= n; i++)
  {
    if(i == c)
    {
      index++;
    }
    if(str[i - 1] == '4' || str[i - 1] == '7')
    {
      a[index] += (int)(str[i - 1] - '0');
      continue;
    }
    a[0] = -1;
    break;
  }
  if(a[0] == a[1])
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
}