#include <stdio.h>
#include <math.h>

#define M_PI       3.14159265358979323846

int main()
{
  double l, r;
  scanf("%lf %lf", &l, &r);
  //l = 10; r = 6;
  double answer = 0.0;
  answer = r * r * M_PI;
  double h = r - l / 2.0;
  if(r >= l / 1.4142135623730950488016887242097)
  {
    answer = l * l;
  }
  else if(h > 0.0)
  {
    double angle = 2 * acos(1.0 - h / r);
    answer -= 4 * 0.5 * r * r * (angle - sin(angle));
  }
  printf("%lf\n", answer);
  return 0;
}