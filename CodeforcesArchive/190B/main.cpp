#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

int X1, Y1, R1;
int X2, Y2, R2;

void ReadData()
{
  scanf("%d %d %d", &X1, &Y1, &R1);
  scanf("%d %d %d", &X2, &Y2, &R2);
}

double answer;

void Solve()
{
  int distance = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);
  if(distance > (R1 + R2) * (R1 + R2))
  {
    answer = (-sqrt((double)distance) + R1 + R2) / 2.0;
    return;
  }
  if(distance == (R1 + R2) * (R1 + R2))
  {
    answer = 0.0;
    return;
  }
  if(R2 > R1)
  {
    std::swap(X1, X2);
    std::swap(Y1, Y2);
    std::swap(R1, R2);
  }
  if(R1 - sqrt((double)distance) <= R2)
  {
    answer = 0.0;
    return;
  }
  answer = (-sqrt((double)distance) + R1 - R2) / 2.0;
}

void WriteData()
{
  printf("%.10lf\n", abs(answer));
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