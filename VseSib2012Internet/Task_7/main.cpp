#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double ld, wd, xd, yd, rd;
__int64 l, w, x, y, r;

void ReadData()
{
  scanf("%lf %lf %lf %lf %lf", &ld, &wd, &xd, &yd, &rd);
  //printf("%lf %lf %lf %lf %lf\n", l, w, x, y, r);
  l = floor(ld * 100000.0 + 0.5);
  w = floor(wd * 100000.0 + 0.5);
  x = floor(xd * 100000.0 + 0.5);
  y = floor(yd * 100000.0 + 0.5);
  r = floor(rd * 100000.0 + 0.5);
}

__int64 distance(__int64 x1, __int64 y1, __int64 x2, __int64 y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool answer;

void Solve()
{
  answer = false;
  if((x >= 0 && x <= l && y >= -r && y <= w + r)
    || (y >= 0 && y <= w && x >= -r && x <= l + r))
  {
    answer = true;
    return;
  }
  if((distance(0, 0, x, y) <= r * r)
    || (distance(l, 0, x, y) <= r * r)
    || (distance(0, w, x, y) <= r * r)
    || (distance(l, w, x, y) <= r * r))
  {
    answer = true;
    return;
  }
}

void WriteData()
{
  if(answer)
  {
    printf("In\n");
  }
  else
  {
    printf("Out\n");
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int QWE;
  scanf("%d%*c", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}