#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

inline double pow2(double val);

struct point2d
{
  double x, y;

  point2d operator +(const point2d &obj)
  {
    point2d result = {x + obj.x, y + obj.y};
    return result;
  }

  point2d operator -(const point2d &obj)
  {
    point2d result = {x - obj.x, y - obj.y};
    return result;
  }

  point2d operator *(const point2d &obj)
  {
    point2d result = {x * obj.x, y * obj.y};
    return result;
  }

  point2d operator *(double val)
  {
    point2d result = {x * val, y * val};
    return result;
  }

  point2d& operator *=(double val)
  {
    x *= val;
    y *= val;
    return *this;
  }

  point2d operator /(double val)
  {
    point2d result = {x / val, y / val};
    return result;
  }

  point2d& operator +=(const point2d &obj)
  {
    x += obj.x;
    y += obj.y;
    return *this;
  }

  point2d& operator -=(const point2d &obj)
  {
    x -= obj.x;
    y -= obj.y;
    return *this;
  }

  point2d& operator =(double val)
  {
    x = val;
    y = val;
    return *this;
  }

  point2d getCopyWithLen(double newLen)
  {
    point2d result = {newLen * x / getLen(), newLen * y / getLen()};
    return result;
  }

  double getLen()const
  {
    return sqrt(pow2(x) + sqrt(pow2(y)));
  }
};

struct circle
{
  point2d pos, speed;
  double r, m;
};

circle c1, c2;
double t;

void ReadData()
{
  scanf("%lf %lf %lf %lf %lf %lf", &c1.pos.x, &c1.pos.y,
    &c1.speed.x, &c1.speed.y, &c1.r, &c1.m);
  scanf("%lf %lf %lf %lf %lf %lf", &c2.pos.x, &c2.pos.y,
    &c2.speed.x, &c2.speed.y, &c2.r, &c2.m);
  scanf("%lf", &t);
}

inline double pow2(double val)
{
  return val * val;
}

void presentationError()
{
  printf("FFFUUUUUUUUUUUUUUUUUUUUU\n");
  exit(0);
}

bool solved;
pair<double, double> solveQuadraticEquation(double A, double B, double C)
{
  solved = false;
  if(A == 0.0)
  {
    if(B == 0.0)
    {
      if(C != 0.0)
      {
        //presentationError();
        return make_pair(-1, -1);
      }
      solved = true;
      return make_pair(0, 0);
    }
    solved = true;
    return make_pair(-C / B, -C / B);
  }
  double d = pow2(B) - 4 * A * C;
  if(d < 0)
  {
    solved = false;
    return make_pair(-1, -1);
  }
  solved = true;
  d = sqrt(d);
  pair<double, double> result;
  result.first = (-B + d) / (2.0 * A);
  result.second = (-B - d) / (2.0 * A);
  return result;
}

double cross(const point2d &p1, const point2d &p2, const point2d &p3)
{
  double x1 = p2.x - p1.x;
  double y1 = p2.y - p1.y;
  double x2 = p3.x - p1.x;
  double y2 = p3.y - p1.y;
  return x1 * y2 - x2 * y1;
}

double cross(const point2d &v1, const point2d &v2)
{
  return v1.x * v2.y - v2.x * v1.y;
}


double getCos(const point2d &p1, const point2d &p2)
{
  return (p1.x * p2.x + p1.y * p2.y) / (p1.getLen() * p2.getLen());
}

circle ac1, ac2;

void easySolve()
{
  ac1.speed = c1.speed;
  ac2.speed = c2.speed;
  ac1.pos = c1.pos + c1.speed * t;
  ac2.pos = c2.pos + c2.speed * t;
}

void Solve()
{
  //BEGIN –еша€ квадратное уравнение, находим врем€ столкновени€
  double a, b, c;
  a = pow2(c1.speed.x - c2.speed.x) + pow2(c1.speed.y - c2.speed.y);
  b = (2 * c1.pos.x - 2 * c2.pos.x) * (c1.speed.x - c2.speed.x)
    + (2 * c1.pos.y - 2 * c2.pos.y) * (c1.speed.y - c2.speed.y);
  double d2 = pow2(c1.r + c2.r);
  c = pow2(c1.pos.x - c2.pos.x) + pow2(c1.pos.y - c2.pos.y) - d2;
  pair<double, double> connectionTime = solveQuadraticEquation(a, b, c);
  //END –еша€ квадратное уравнение, находим врем€ столкновени€

  double realConnectionTime = min(max(0.0, connectionTime.first), max(0.0, connectionTime.second));
  //≈сли уравнение не имеет решени€ или встреча произойдЄт после времени t
  if(solved == false || realConnectionTime == 0.0 || realConnectionTime >= t)
  {
    easySolve();
    return;
  }

  //BEGIN перевод в новую систему координат
  circle c1copy = c1;
  circle c2copy = c2;
  c1.pos -= c2.pos;
  c1.speed -= c2.speed;
  c2.pos = 0.0;
  c2.speed = 0.0;
  //END перевод в новую систему координат
  
  point2d centralVector = c2.pos - (c1.pos + c1.speed * realConnectionTime);
  double centralVectorLen = centralVector.getLen();
  double v1 = c1.speed.getLen();
  double v1OnCentralVector = v1 * getCos(centralVector, c1.speed);
  if(v1OnCentralVector < 0)
  {
    presentationError();
  }

  point2d yComponent = {-centralVector.y, centralVector.x};
  if(cross(centralVector, yComponent) * cross(centralVector, c1.speed) < 0)
  {
    yComponent *= -1.0;
  }
  double ySpeed = sqrt(abs(pow2(v1) - pow2(v1OnCentralVector)));
  yComponent = yComponent * (ySpeed / centralVectorLen);
  
  a = c1.m * c2.m + pow2(c2.m);
  b = -2.0 * c1.m * c2.m * v1OnCentralVector;
  c = 0;
  pair<double, double> v2Speeds = solveQuadraticEquation(a, b, c);
  double newV2Speed = v2Speeds.first == 0 ? v2Speeds.second : v2Speeds.first;
  if(v2Speeds.first != 0.0 && v2Speeds.second != 0.0)
  {
    throw;
  }
  double newV1Speed = (c1.m * v1OnCentralVector - c2.m * newV2Speed) / c1.m;

  //ƒо столкновени€
  ac1.pos = c1copy.pos + c1copy.speed * realConnectionTime;
  ac2.pos = c2copy.pos + c2copy.speed * realConnectionTime;
  //ѕосле столкновени€
  double otherTime = t - realConnectionTime;
  
  ac1.speed = centralVector.getCopyWithLen(newV1Speed) + yComponent;
  ac2.speed = centralVector.getCopyWithLen(newV2Speed);

  ac1.pos += ac1.speed * otherTime + c2copy.speed * t;
  ac2.pos += ac2.speed * otherTime + c2copy.speed * t;

  ac1.speed += c2copy.speed;
  ac2.speed += c2copy.speed;
}

void WriteData()
{
  printf("%.5lf %.5lf %.5lf %.5lf\n", ac1.pos.x, ac1.pos.y, ac1.speed.x, ac1.speed.y);
  printf("%.5lf %.5lf %.5lf %.5lf\n", ac2.pos.x, ac2.pos.y, ac2.speed.x, ac2.speed.y);
  printf("\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}