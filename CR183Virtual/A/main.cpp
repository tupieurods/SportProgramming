#include <stdio.h>
#include <math.h>

int main()
{
  int n, answer;
  scanf("%d", &n);
  answer = 0;
  for(int a = 1; a <= n; a++)
  {
    for(int b = 1; b <= n; b++)
    {
      int c = a * a + b * b;
      if(c <= n * n)
      {
        int val = (int)sqrt((double)c);
        if(val * val == c)
          answer++;
      }
    }
  }
  printf("%d\n", answer / 2);
  return 0;
}