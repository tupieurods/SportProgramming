#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point3d
{
  long double x, y, z;
};

long double ab, ac, ad, bc, bd, cd;
point3d a, b, c, d;
int arr[6];

int compare(const void *v1, const void *v2)
{
  return *(int*)v2 - *(int*)v1;
}

void ReadData()
{
  scanf("%lf %lf %lf %lf %lf %lf", &ab, &ac, &ad, &bc, &bd, &cd);;
}

inline long double pow2(long double v1)
{
  return v1 * v1;
}

long double answer;

void Solve()
{
  answer = -1;
  a.z = 0;
  b.z = 0;
  b.y = 0;
  b.x = 10.0;
  c.z = 0;
  c.y = 0;
  c.x = 10.0 + bc;
  //double tmp1 = (pow2(c.x) - pow2(b.x) + pow2(ab) - pow2(ac));
  //double tmp2 = 2.0 * (c.x - b.x);
  a.x = (pow2(c.x) - pow2(b.x) + pow2(ab) - pow2(ac)) / (2.0 * (c.x - b.x));
  if(pow2(ac) - pow2(a.x) + 2.0 * a.x * c.x - pow2(c.x) < 0.0)
  {
    printf("ERROR");
    //answer = 0;
    return;
  }
  a.y = sqrt(pow2(ac) - pow2(a.x) + 2.0 * a.x * c.x - pow2(c.x));
  //»щем точку D
  d.x = (pow2(bd) - pow2(cd) + pow2(c.x) - pow2(b.x)) / (2.0 * (c.x - b.x));
  long double F = pow2(b.x) - pow2(a.x) - pow2(a.y) - 2.0 * d.x * b.x + 2.0 * d.x * a.x;
  if(abs(a.y) <= 1e-8)
  {
    printf("ERROR");
    //answer = 0;
    return;
  }
  d.y = (pow2(ad) - pow2(bd) + F) / (-2.0 * a.y);
  if(pow2(ad) - pow2(d.x - a.x) - pow2(d.y - a.y) < 0.0)
  {
    printf("ERROR");
    //answer = 0;
    return;
  }
  d.z = sqrt(pow2(ad) - pow2(d.x - a.x) - pow2(d.y - a.y));
  answer = ((d.z - b.z) * a.y * (c.x - b.x)) / 6.0;
  if(answer < 0.0)
  {
    printf("ERROR");
    //answer = 0;
    return;
  } 
}

void WriteData()
{
  printf("%.6lf\n", answer);
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