#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double n, table, r;
double a;

void ReadData()
{
  scanf("%lf %lf %lf", &n, &table, &r);
}

void Solve()
{
  a = (table - r) * sin(M_PI / n);
}

void WriteData()
{
  if(table < r || (n > 1 && a + 1e-7 < r))
  {
    printf("NO\n");
  }
  else
  {
    printf("YES\n");
  }
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