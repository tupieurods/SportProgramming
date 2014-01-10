#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char str[109];
  scanf("%s", str);
  int len = strlen(str);
  int a[3] = {0, 0, 0};
  int cnt = 0;
  for(int i = 0; i < len; i++)
  {
    if(str[i] != '+')
    {
      a[str[i] - '0' - 1]++;
      cnt++;
    }
  }
  int current = 0;
  while(cnt != 0)
  {
    if(a[current] == 0)
    {
      current++;
      continue;
    }
    printf("%d", current + 1);
    if(cnt != 1)
    {
      printf("+");
    }
    a[current]--;
    cnt--;
  }
  printf("\n");
  return 0;
}