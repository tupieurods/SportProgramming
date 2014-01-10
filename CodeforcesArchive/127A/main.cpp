#include <stdio.h>
#include <math.h>

int n, k;
double answer;

double distance(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void ReadData()
{
  scanf("%d %d", &n, &k);
  answer = 0.0;
  double x, y;
  scanf("%lf %lf", &x, &y);
  for(int i = 1; i < n; i++)
  {
    double cX, cY;
    scanf("%lf %lf", &cX, &cY);
    answer += distance(x, y, cX, cY);
    x = cX;
    y = cY;
  }
}

void Solve()
{
  answer *= k;
}

void WriteData()
{
  printf("%.10f\n", answer / 50.0);
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