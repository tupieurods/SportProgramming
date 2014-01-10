//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//#include <algorithm>
//
//using namespace std;
//
//#define M_PI 3.14159265358979323846
//
//struct point2f
//{
//  long double x, y;
//};
//
//int n, n1, n2;
//point2f n1p, n2p;
//point2f testCenter;
//long double testR, testPhi0;
//
//float rand_FloatRange(float a, float b)
//{
//  return a + (float)rand()/((float)RAND_MAX/(b-a));;
//}
//
//void ReadData()
//{
//  n = rand() % 15 + 3;
//  n1 = rand() % n + 1;
//  n2 = n1;
//  while(n1 == n2)
//  {
//    n2 = rand() % n + 1;
//  }
//  testPhi0 = rand() % 360;
//  testPhi0 =  (testPhi0 * M_PI) / 180.0;;
//  testR = rand_FloatRange(0.0, 41.0);
//  testCenter.x = rand_FloatRange(-1000000.0, 1000000.0);
//  testCenter.y = rand_FloatRange(-1000000.0, 1000000.0);
//  n1p.x = testCenter.x + testR * cos(-(testPhi0 + (2.0 * M_PI * (n1 - 1)) / n));
//  n1p.y = testCenter.y + testR * sin(-(testPhi0 + (2.0 * M_PI * (n1 - 1)) / n));
//  n2p.x = testCenter.x + testR * cos(-(testPhi0 + (2.0 * M_PI * (n2 - 1)) / n));
//  n2p.y = testCenter.y + testR * sin(-(testPhi0 + (2.0 * M_PI * (n2 - 1)) / n));
//}
//
//inline long double pow2(long double val)
//{
//  return val * val;
//}
//
//point2f answer[159];
//
//bool TryToBuildAnswer(long double angle, point2f center)
//{
//  point2f newN1P;
//  newN1P.x = n1p.x - center.x;
//  newN1P.y = n1p.y - center.y;
//  int current = n1;
//  for(int i = 0; i < n; i++)
//  {
//    answer[current].x = newN1P.x * cos(angle * i) - newN1P.y * sin(angle * i) + center.x;
//    answer[current].y = newN1P.x * sin(angle * i) + newN1P.y * cos(angle * i) + center.y;
//    if(current == n2
//      && abs(n2p.x - answer[current].x) > 1e-6
//      && abs(n2p.y - answer[current].y) > 1e-6)
//    {
//      return false;
//    }
//    current++;
//    if(current > n)
//    {
//      current = 1;
//    }
//  }
//  return true;
//}
//
//void Solve()
//{
//  memset(answer, 0, sizeof(answer));
//  long double a0 = ((n - 2.0) * 180.0) / n;
//  //long double b0 = 180.0 - a0;
//  a0 = 180.0 - a0;
//  int n1min = min(n1, n2);
//  int n2max = max(n1, n2);
//  long double da = a0 * (n2max - n1min);//min((n2max - n1min) * a0, 180.0 * (n - 2) - (n2max - n1min) * a0);
//  long double b = (da * M_PI) / 180.0;
//  long double R2 = (pow2(n1p.x - n2p.x) + pow2(n1p.y - n2p.y)) / (2.0 - 2.0 * cos(b));
//  //printf("R^2:%.6lf\n", R2);
//  if(abs(sqrt(R2) - testR) > 1e-6)
//    printf("calced: %.8lf realR: %.8lf\n", sqrt(R2), testR);
//  long double a = 2.0 * sqrt(R2) * sin(M_PI / n);
//  //printf("a:%.6lf\n", a);
//  long double l = sqrt(R2) * cos((da * M_PI) / 360.0);
//  //printf("l:%.6lf\n", l);
//  point2f hordC;
//  hordC.x = (n1p.x - n2p.x) / 2.0 + n2p.x;
//  hordC.y = (n1p.y - n2p.y) / 2.0 + n2p.y;
//  //printf("hordC x:%.6lf y:%.6lf\n", hordC.x, hordC.y);
//  long double A = n2p.y - n1p.y;
//  long double B = n1p.x - n2p.x;
//  point2f center;
//  center.x = hordC.x + (A * l) / sqrt(pow2(A) + pow2(B));
//  center.y = hordC.y + (B * l) / sqrt(pow2(A) + pow2(B));
//  //printf("center x:%.6lf y:%.6lf\n", center.x, center.y);
//  int current = n1;
//  a0 = -(a0 * M_PI) / 180.0;
//  if(!TryToBuildAnswer(a0, center))
//  {
//    center.x = hordC.x - (A * l) / sqrt(pow2(A) + pow2(B));
//    center.y = hordC.y - (B * l) / sqrt(pow2(A) + pow2(B));
//    TryToBuildAnswer(a0, center);
//    /*if(!TryToBuildAnswer(a0, center))
//    throw;*/
//  }
//}
//
//int accepted;
//void WriteData()
//{
//  for(int i = 1; i <= n; i++)
//  {
//    long double xCheck = testCenter.x + testR * cos(-(testPhi0 + (2.0 * M_PI * (i - 1)) / n));
//    long double yCheck = testCenter.y + testR * sin(-(testPhi0 + (2.0 * M_PI * (i - 1)) / n));
//    if(abs(answer[i].x - xCheck) > 1e-6 || abs(answer[i].y - yCheck) > 1e-6)
//    {
//      printf("WA. Dot: %d\n", i);
//      printf("input: %d %d %d\n", n, n1, n2);
//      printf("center: %.6lf %.6lf\n", testCenter.x, testCenter.y);
//      printf("R: %.6lf phi0: %.6lf\n", testR, testPhi0);
//      printf("n1 x:%.6lf y:%.6lf\n", n1p.x, n1p.y);
//      printf("n2 x:%.6lf y:%.6lf\n", n2p.x, n2p.y);
//      return;
//    }
//    //printf("%.8lf %.8lf\n", answer[i].x, answer[i].y);
//    //printf("%.8lf %.8lf\n\n", xCheck, yCheck);
//  }
//  printf("test accepted\n");
//  accepted++;
//  //printf("\n");
//}
//
//int main()
//{
//  int QWE = 1500;
//#ifndef ONLINE_JUDGE
//  //freopen("input.txt", "r", stdin);
//  //srand(time(NULL));
//  freopen("output.txt", "w", stdout);
//  //scanf("%d", &QWE);
//#endif
//  accepted = 0;
//  for(int T = 0; T < QWE; T++)
//  {
//    printf("test ¹%d\n", T + 1);
//    ReadData();
//    Solve();
//    WriteData();
//  }
//  printf("Accepted count: %d\n", accepted);
//  return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <algorithm>

using namespace std;

#define M_PI 3.14159265358979323846

struct point2f
{
  long double x, y;
};

int n, n1, n2;
point2f n1p, n2p;

void ReadData()
{
  scanf("%d %d %d", &n, &n1, &n2);
  if(n > 150)
    throw;
  if(n1 < 1 || n1 > n)
    throw;
  if(n2 < 1 || n2 > n)
    throw;
  if(n1 == n2)
    throw;
  scanf("%lf %lf", &n1p.x, &n1p.y);
  if(abs(n1p.x) > 2000000.0 || abs(n1p.y) > 2000000.0)
    throw;
  scanf("%lf %lf", &n2p.x, &n2p.y);
  if(abs(n2p.x) > 2000000.0 || abs(n2p.y) > 2000000.0)
    throw;
}

inline long double pow2(long double val)
{
  return val * val;
}

point2f answer[159];

bool TryToBuildAnswer(long double angle, point2f center)
{
  point2f newN1P;
  newN1P.x = n1p.x - center.x;
  newN1P.y = n1p.y - center.y;
  int current = n1;
  for(int i = 0; i < n; i++)
  {
    answer[current].x = newN1P.x * cos(angle * i) - newN1P.y * sin(angle * i) + center.x;
    answer[current].y = newN1P.x * sin(angle * i) + newN1P.y * cos(angle * i) + center.y;
    if(current == n2
        && abs(n2p.x - answer[current].x) > 1e-6
        && abs(n2p.y - answer[current].y) > 1e-6)
    {
      return false;
    }
    current++;
    if(current > n)
    {
      current = 1;
    }
  }
  return true;
}

void Solve()
{
  memset(answer, 0, sizeof(answer));
  long double a0 = ((n - 2) * 180.0) / n;
  a0 = 180.0 - a0;
  int n1min = min(n1, n2);
  int n2max = max(n1, n2);
  long double da = min((n2max - n1min) * a0, 360.0 - (n2max - n1min) * a0);
  long double b = (da * M_PI) / 180.0;
  long double R2 = (pow2(n1p.x - n2p.x) + pow2(n1p.y - n2p.y)) / (2.0 - 2.0 * cos(b));
  //printf("R^2:%.6lf\n", R2);
  long double a = 2.0 * sqrt(R2) * sin(M_PI / n);
  //printf("a:%.6lf\n", a);
  long double l = sqrt(R2) * cos((da * M_PI) / 360.0);
  //printf("l:%.6lf\n", l);
  point2f hordC;
  hordC.x = (n1p.x - n2p.x) / 2.0 + n2p.x;
  hordC.y = (n1p.y - n2p.y) / 2.0 + n2p.y;
  //printf("hordC x:%.6lf y:%.6lf\n", hordC.x, hordC.y);
  long double A = n2p.y - n1p.y;
  long double B = n1p.x - n2p.x;
  point2f center;
  center.x = hordC.x + (A * l) / sqrt(pow2(A) + pow2(B));
  center.y = hordC.y + (B * l) / sqrt(pow2(A) + pow2(B));
  //printf("center x:%.6lf y:%.6lf\n", center.x, center.y);
  int current = n1;
  a0 = -(a0 * M_PI) / 180.0;
  if(!TryToBuildAnswer(a0, center))
  {
    center.x = hordC.x - (A * l) / sqrt(pow2(A) + pow2(B));
    center.y = hordC.y - (B * l) / sqrt(pow2(A) + pow2(B));
    TryToBuildAnswer(a0, center);
    /*if(!TryToBuildAnswer(a0, center))
      throw;*/
  }
}

void WriteData()
{
  for(int i = 1; i <= n; i++)
  {
    printf("%.6lf %.6lf\n", answer[i].x, answer[i].y);
  }
  printf("\n");
}

float rand_FloatRange(float a, float b)
{
  return a + (float)rand()/((float)RAND_MAX/(b-a));;
}

int main()
{
  if(!true)
  {
    //freopen("output2.txt", "w", stdout);
    int nval = 4, n1val = 1, n2val = 3;
    point2f center;
    center.x = 1.0;
    center.y = 1.0;
    long double r = 1.0;
    long double phi0 = ((90.0 * M_PI) / 180.0);
    for(int i = 1; i <= nval; i++)
    {
      long double xval = center.x + r * cos(-(phi0 + (2.0 * M_PI * (i - 1)) / (1.0 * nval)));
      long double yval = center.y + r * sin(-(phi0 + (2.0 * M_PI * (i - 1)) / (1.0 * nval)));
      printf("%.6lf %.6lf\n", xval, yval);
    }
    return 0;
  }
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n");
    srand(time(NULL));
    for(int i = 0; i < 1; i++)
    {
      int cnt = rand() % 150 + 3;
      printf("%d %d %d\n", cnt, rand() % cnt + 1, rand() % cnt + 1);
      printf("%.6lf %.6lf\n", rand_FloatRange(-2000000.0, 2000000.0), rand_FloatRange(-2000000.0, 2000000.0));
      printf("%.6lf %.6lf\n", rand_FloatRange(-2000000.0, 2000000.0), rand_FloatRange(-2000000.0, 2000000.0));
    }
    return 0;
  }
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
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