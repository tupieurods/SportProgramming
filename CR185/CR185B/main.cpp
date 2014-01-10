#include <stdio.h>
#include <math.h>

int main()
{
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  double k1 = (double)(b - a) / (double)b;
  double k2 = (double)(d - c) / (double)d;
  double k3 = (double)a / (double)b;
  double answer = k3;
  for(int i = 1; i <= 100000; i++)
  {
    answer += k3 * pow(k1, (double)i) * pow(k2, (double)i);
  }
  printf("%.20f", answer);
  return 0;
}