#include <stdio.h>
#include <math.h>

int n;
double vBus, vStudent;
int xU, yU;

double distance(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int *stops;

void ReadData()
{
  scanf("%d %lf %lf", &n, &vBus, &vStudent);
  stops = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &stops[i]);
  }
  scanf("%d %d", &xU, &yU);
}

double minTime;
int answer;

void Solve()
{
  answer = 0;
  minTime = 1e10;
  for(int i = 1; i < n; i++)
  {
    double current = (double)stops[i] / vBus
      + distance(stops[i], 0, xU, yU) / vStudent;
    if(current <= minTime)
    {
      minTime = current;
      answer = i;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer + 1);
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