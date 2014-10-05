#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int answer = 0;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int p, q;
    scanf("%d %d", &p, &q);
    if(q - p >= 2)
    {
      answer++;
    }
  }
  printf("%d\n", answer);
  return 0;
}