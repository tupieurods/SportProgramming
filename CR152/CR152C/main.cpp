#include <stdio.h>
#include <cmath>
#include <cstdlib>

using namespace std;

double y2, yW, xB, yB, r;

double center(double left, double right)
{
  return ((right - left) / 2) + left;
}

double calcY(double xW, double yB, double xB, double yW)
{
  //printf("%lf\n", (yW * xB - xW * yB) / (xB - xW));
  return (yW * xB - xW * yB) / (xB - xW);
}

double getDistance(double a, double b, double c)
{
  return abs((a * 0 - b * y2 + c) / (sqrt(a * a + b * b)));
}

int main()
{
  double y1;
  scanf("%lf %lf %lf %lf %lf %lf", &y1, &y2, &yW, &xB, &yB, &r);
  //xB = -xB;
  if((y2 - y1) <= 2 * r)
  {
    printf("-1\n");
    return 0;
  }
  yW -= r;
  double xLeft = 0;
  double xRight = xB;
  do
  {
    if(xRight - xLeft < 10e-9)
    {
      printf("-1\n");
      return 0;
    }
    double x = center(xLeft, xRight);
    //printf("x: %lf %lf %lf %lf\n", x, yB, -xB + x * 2, yW);
    double yC = calcY(x, yB, -xB + x * 2, yW);
    //printf("left: %lf right: %lf y: %lf\n", xLeft, xRight, yC);
    //printf("%lf\n", getDistance(yB - yW, -xB + x * 2 - x, -x * (yB - yW)+ yW * (-xB + x * 2 - x)));
    if((getDistance(yB - yW, -xB + x * 2 - x, -x * (yB - yW)+ yW * (-xB + x * 2 - x)) > r) && (yC >= y1) && (yC < y2))
    {
      printf("%0.10lf\n", x);
      return 0;
      break;
    }
    if(yC < y1)
      xRight = x;
    else
      xLeft = x;
    //printf("%0.8lf\n", x);
    //system("pause");
  } while(true);
  return 0;
}
