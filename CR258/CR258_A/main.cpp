#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int answer = std::min(n, m);
  if(answer % 2 == 0)
  {
    printf("Malvika\n");
  }
  else
  {
    printf("Akshat\n");
  }
  return 0;
}