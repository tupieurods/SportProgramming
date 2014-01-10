#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct line
{
  double A, B, C;
};

double xl, yl, cl;

inline double pow2(double val)
{
  return val * val;
}

line build_line(double x1, double x2, double y1, double y2)
{
  line result;
  result.A = y2 - y1;
  result.B = x1 - x2;
  result.C = x1 * (y1 - y2) + y1 * (x2 - x1);
  return result;
}

double getYIntersect(line &l1, line &l2)
{
  return -(l1.A * l2.C - l2.A * l1.C) / (l1.A * l2.B - l2.A * l1.B);
}

double check(double value)
{
  line l1 = build_line(0.0, value, sqrt(pow2(xl) - pow2(value)), 0.0);
  line l2 = build_line(0.0, value, 0.0, sqrt(pow2(yl) - pow2(value)));
  return getYIntersect(l1, l2);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  while(scanf("%lf %lf %lf", &xl, &yl, &cl) != EOF)
  {
    double answer;
    double l = 0.0, r = max(xl, yl);
    while(r - l > 1e-6)
    {
      double a = l + (r - l) / 2.0;
      answer = a;
      double tmp = check(a);
      if(tmp < 0)
        throw;
      if(tmp > cl)
      {
        l = a;
      }
      else
      {
        r = a;
      }
    }
    printf("%.3lf\n", answer);
  }
  return 0;
}