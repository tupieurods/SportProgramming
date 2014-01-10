#include <stdio.h>
#include <stdlib.h>

int main()
{
  int d, a[4];
  scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &d);
  int answer = 0;
  for(int i = 1; i <= d; i++)
  {
    int c = 0;
    for(int j = 0; j < 4; j++)
    {
      if(i % a[j] == 0)
      {
        c++;
      }
    }
    answer += (int)(c > 0);
  }
  printf("%d\n", answer);
  return 0;
}