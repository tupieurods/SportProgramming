#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cerrno>

double c, b, m;

void ReadData()
{
  scanf("%lf %lf %lf", &c, &b, &m);
}

double answer, xm, ym;
bool constructed;

bool AlessB(double v1, double v2)
{
  if(v2 - v1> 1e-8)
  {
    return true;
  }
  return false;
}

void Solve()
{
  constructed = false;
  if((c == b) && (b == m))
  {
    constructed = true;
    answer = 0.0;
    xm = 0.0;
    ym = m;
    return;
  }
  //if(2.0 * (c * c + b * b - 2.0 * m * m) > 1e-8)
  if(AlessB(4.0 * m * m, 2.0 * (b * b + c * c)))
  {
    answer = sqrt(2.0 * (c * c + b * b - 2.0 * m * m));
    if(errno == EDOM)
      throw;
    if(!((answer <= c + b) && (b <= c + answer) && (c <= answer + b)))
    //if(!(AlessB(answer, c + b) && AlessB(b, c + answer) && AlessB(c, answer + b)))
    {
      return;
    }
    constructed = true;
    double x1 = -answer / 2.0;
    if(abs(x1) < 1e-5)
      throw;
    xm = (x1 * x1 + m * m - c * c) / (2.0 * x1);
    ym = sqrt(abs(m * m - xm * xm));
    if(errno == EDOM)
      throw;
    /*double x1 = -answer / 2.0;
    double x2 = answer / 2.0;
    xm = (x1 * x1 - x2 * x2 - c * c + b * b) / (2.0 *x1 - 2.0 * x2);
    ym = sqrt(abs(c * c - xm * xm + 2.0 * x1 * xm - x1 * x1));*/
  }
}

void WriteData()
{
  if(!constructed)
  {
    printf("Mission impossible\n");
    return;
  }
  printf("%.5lf %.5lf\n", xm, ym);
  printf("%.5lf %.5lf\n", -answer / 2.0, 0.0);
  printf("%.5lf %.5lf\n", answer / 2.0, 0.0);
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