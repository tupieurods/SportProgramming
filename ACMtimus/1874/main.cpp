#include <stdio.h>
#include <math.h>

int main()
{
  double a, b;
  scanf("%lf %lf", &a, &b);
  double s = (a * a + b * b) / 4.0 + a * b / sqrt(2.0);
  printf("%.10lf\n", s);
}