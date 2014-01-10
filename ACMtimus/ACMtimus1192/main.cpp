#include <stdio.h>
#include <math.h>

double v, a, k, answer;

#define M_PI 3.1415926535

void ReadData()
{
  scanf("%lf %lf %lf", &v, &a, &k);
  a = a * M_PI / 180.0;
  k = sqrt(k);
}

void Solve()
{
  answer =  (2 * v * v * sin(a) * cos(a))/ 10.0;
  v /= k;
  double prevAnswer = answer;
  do
  {
    prevAnswer = answer;
    answer += (2 * v * v * sin(a) * cos(a))/ 10.0;
    v /= k;
  }while(v >= 0.000001);
}

void WriteData()
{
  printf("%.2lf", answer);
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