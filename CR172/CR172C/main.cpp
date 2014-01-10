#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
  double x, y;
};

double toRadian(double v)
{
  return (v * M_PI) / 180.0;
}

Point solve(Point p01, Point p11, Point p02, Point p12)
{
  Point* result = new Point;
  double a1 = p11.y - p01.y;
  double a2 = p12.y - p02.y;
  double b1 = p01.x - p11.x;
  double b2 = p02.x - p12.x;
  double c1 = -p01.x * p11.y + p11.x * p01.y;
  double c2 = -p02.x * p12.y + p12.x * p02.y;
  result->y = (c1 * a2 - c2 * a1) / (b2 * a1 - a2 * b1);
  result->x = (-c2 - b2 * result->y) / a2;
  return *result;
}

double dist(Point a, Point b)
{
  return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main()
{
  int w, h, a;
  scanf("%d %d %d", &w, &h, &a);
  double nW = w, nH = h, nA;
  if(a == 180 || a == 0)
  {
    printf("%.10f", nW * nH);
    return 0;
  }
  if(w < h)
  {
    swap(nW, nH);
  }
  Point data[8] = {
    { -nW / 2.0, -nH / 2.0},
    {nW / 2.0, -nH / 2.0},
    {nW / 2.0, nH / 2.0},
    { -nW / 2.0, nH / 2.0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
  };
  if(a >= 90)
    a = 180 - a;
  nA = a;
  for(int i = 0; i < 4; i++)
  {
    data[i + 4] =
    {
      data[i].x * cos(toRadian(nA)) - data[i].y * sin(toRadian(nA)),
      data[i].x * sin(toRadian(nA)) + data[i].y * cos(toRadian(nA))
    };
  }
  Point s;
  if(a == 90)
  {
    s = solve(data[0], data[1], data[4], data[5]);
    printf("%.10f", dist(s, { -s.x, s.y}) * dist(s, {s.x, -s.y}));
    return 0;
  }
  Point data2[4] =
  {
    solve(data[0], data[1], data[4], data[5]),
    solve(data[4], data[5], data[1], data[2]),
    solve(data[5], data[6], data[1], data[2]),
    solve(data[2], data[3], data[5], data[6]),
  };
  double s1 = 0;
  if(data2[1].y > data[2].y)
  {
    //Переходим на вычислени площади трапеции
    data2[3] = solve(data[2], data[3], data[4], data[5]);
    s1 = nH * (dist(data2[0], data[1]) + dist(data2[3], data[2]));
  }
  else
  {
    s1 += dist(data[1], data2[0]) * dist(data2[1], data2[0]) * sin(toRadian(nA));
    s1 += dist(data[2], data2[2]) * dist(data2[2], data2[3]) * sin(toRadian(nA));
  }
  printf("%.10f", nW * nH - s1);
  return 0;

  return 0;
}
