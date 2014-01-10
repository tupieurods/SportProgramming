#include <stdio.h>

int main()
{
  __int64 k, l;
  scanf("%I64d %I64d", &k, &l);
  int answer = -1;
  __int64 current = k;
  for(int i = 0; i < 32; i++)
  {
    if(current > l)
    {
      break;
    }
    if(current == l)
    {
      answer = i;
      break;
    }
    current *= k;
  }
  if(answer == -1)
  {
    printf("NO\n");
  }
  else
  {
    printf("YES\n%d\n", answer);
  }
  return 0;
}