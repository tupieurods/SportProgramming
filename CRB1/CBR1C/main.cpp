#include <stdio.h>
#include <cmath>

using namespace std;

double len(double x1, double y1, double x2, double y2)
{
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double gcd(double x, double y)
{
  double eps=0.0001;
  while (fabs(x) > eps && fabs(y) > eps) {
      if (x > y)
        x -= floor(x / y) * y;
      else
        y -= floor(y / x) * x;
    }
  return x + y;
}

int main()
{
  double **inData = new double*[3];
  for(int i = 0; i < 3; i++)
    {
      inData[i] = new double[2];
      scanf("%lf %lf", &inData[i][0], &inData[i][1]);
    }
  double a = len(inData[0][0], inData[0][1], inData[1][0], inData[1][1]);
  double b = len(inData[2][0], inData[2][1], inData[1][0], inData[1][1]);
  double c = len(inData[0][0], inData[0][1], inData[2][0], inData[2][1]);
  double p = (a + b + c) / 2;
  double S = sqrt(p * (p - a) * (p - b) * (p - c));
  double R = (a * b * c ) / (4 * S);
  double A = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
  double B = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c));
  double C = acos((pow(b, 2) + pow(a, 2) - pow(c, 2)) / (2 * b * a));
  double n = M_PI / gcd(gcd(A, B), C);
  printf("%lf", (n / 2) * pow(R, 2)*sin(2 * M_PI / n));
}
