#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
double a, d;

void ReadData()
{
  scanf("%d %lf %lf", &n, &a, &d);
}

void Solve()
{
  double prev = -1.0;
  for(int i = 0; i < n; i++)
  {
    double t, v;
    scanf("%lf %lf", &t, &v);
    double s = v * v / (2.0 * a);
    double at = v / a;
    double resultT = t;
    if(s <= d)
    {
      resultT += at;
      s = d - s;
      resultT += s / v;
    }
    else
    {
      resultT += sqrt((2.0 * d) / a);
    }
    if(resultT <= prev)
    {
      resultT = prev;
    }
    else
    {
      prev = resultT;
    }
    printf("%.5lf\n", resultT);
  }
}

void WriteData()
{
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