#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  double v, h;
  scanf("%lf %lf", &v, &h);
  v /= 3.6;
  int answer = 10 * (v * v / h);
  if(answer % 10 < 5)
  {
    answer /= 10;
  }
  else
  {
    answer /= 10;
    answer++;
  }
  printf("%d\n", answer);
  return 0;
}