#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define LOCALTEST
#define M_PI 3.14159265358979323846

double distance(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
  int n;
  double r;
  cin >> n >> r;
  double xPrev, yPrev, xFirst, yFirst;
  double answer = M_PI * r * 2;
  double x, y;
  cin >> xPrev >> yPrev;
  xFirst = xPrev;
  yFirst = yPrev;
  for(int i = 1; i < n; i++)
  {
    cin >> x >> y;
    answer += distance(xPrev, yPrev, x, y);
    xPrev = x;
    yPrev = y;
  }
  answer += distance(xPrev, yPrev, xFirst, yFirst);
  printf("%.2lf", answer);
  //cout << answer;
  return 0;
}