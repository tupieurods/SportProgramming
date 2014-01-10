#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

long double r1, r2;
long double r12, r22;

void ReadData()
{
  scanf("%lf %lf", &r1, &r2);
  if(r2 > r1)
  {
    std::swap(r1, r2);
  }
}

inline long double pow2(long double x)
{
  return x * x;
}

long double dz;

inline long double f(long double x)
{
  if((r22 - pow2(x)) * (r12 - pow2(x)) < 0.0)
    return 0.0;
  return sqrt(abs((r22 - pow2(x)) * (r12 - pow2(x))));
}

long double answer;

void Solve()
{
  //dz = r2 / 9000000.0;
  //dz = r2 / 9000008.0;
  dz = 1.0;
  do
  {
    dz /= 2.0;
  }while(r2 / dz <= 700000);
  r12 = pow2(r1);
  r22 = pow2(r2);
  answer = 0.0;
  long double prev = f(0.0);
  for(long double z = 0.0; z <= r2; z += dz)
  {
    long double next = f(z + dz);
    answer += prev + 4.0 * f(z + dz / 2.0) + next;
    prev = next;
  }
  answer *= dz * 8.0 / 6.0;
}

void WriteData()
{
  printf("%.4lf\n", answer);
  //printf("%.4lf\n", floor(answer * 10000.0 + 0.5) / 10000.0);
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