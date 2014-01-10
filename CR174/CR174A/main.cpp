#include <stdio.h>

int main()
{
  int p;
  scanf("%d", &p);
  if(p == 2)
  {
    printf("1");
    return 0;
  }
  int answer = 0;
  for(int x = 2; x < p; x++)
  {
    int current = x;
    bool flag = false;
    for(int i = 1; i < p; i++)
    {
      if(((current - 1) % p) == 0)
      {
        if(i == (p - 1))
        {
          flag = true;
        }
        break;
      }
      current = (current * x) % p;
    }
    if(flag)
    {
      answer++;
    }
  }
  printf("%d", answer);
  return 0;
}
