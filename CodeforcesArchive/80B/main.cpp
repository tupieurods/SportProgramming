#include <stdio.h>

int h, m;
double x, y;

void ReadData()
{
  scanf("%d:%d", &h, &m);
}

void Solve()
{
  y = m * 6;
  if(m > 0)
  {
    x = h * 30;
    x += m * 0.5;
  }
  else
  {
    x = h * 30;
  }
  while(x >= 360)
    x -= 360;
  while(y >= 360)
    y -= 360;
}

void WriteData()
{
  printf("%.10f %.10f\n", x, y);
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