#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double l1, l2, l3;

void ReadData()
{
  scanf("%lf %lf %lf", &l1, &l2, &l3);
}

double a, b, R, f1f2;

void Solve()
{
  l1 *= l1, l2 *= l2, l3 *= l3;
  double z = sqrt(l1 * l1 + l2 * l2 + l3 * l3
    - l1 * l2 - l2 * l3 - l3 * l1);
  a = (1.0 / 6.0) * (sqrt(l1 + l2 + l3 + 2.0 * z));
  b = (1.0 / 6.0) * (sqrt(l1 + l2 + l3 - 2.0 * z));
  f1f2 = 2 * sqrt(a * a - b * b);
  R = a;
}

void WriteData()
{
  printf("%.10lf %.10lf\n", f1f2, R);
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}