#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

const double eps = 1e-6;

struct sphere
{
  double x, y, z, r;
};

struct vec3
{
  double x, y, z;
};

int n;
sphere spheres[59];
vec3 start, finish;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%lf %lf %lf %lf", &spheres[i].x, &spheres[i].y,
      &spheres[i].z, &spheres[i].r);
  }
  scanf("%lf %lf %lf", &start.x, &start.y, &start.z);
  scanf("%lf %lf %lf", &finish.x, &finish.y, &finish.z);
}

pair<double, double> failPair = make_pair(-1.0, -1.0);
pair<double, double> solveEquation(double A, double B, double C)
{
  if(abs(A) < eps)
  {
    if(abs(B) < eps)
    {
      return failPair;
    }
    return make_pair(-C / B, -1.0);
  }
  double D = B * B - 4 * A * C;
  if(D < 0)
  {
    return failPair;
  }
  D = sqrt(D);
  return make_pair((-B + D) / (2.0 * A), (-B - D) / (2.0 * A));
}

vec3 getReflection(vec3 A, vec3 B, int sphereIndex)
{
  vec3 N;
  //Нормаль
  N.x = (B.x - spheres[sphereIndex].x) / spheres[sphereIndex].r;
  N.y = (B.y - spheres[sphereIndex].y) / spheres[sphereIndex].r;
  N.z = (B.z - spheres[sphereIndex].z) / spheres[sphereIndex].r;
  /*N.x = 1; N.y = 0; N.z = 0;*/
  //Находим скалярное произведение
  double dotResult = N.x * (B.x - A.x) + N.y * (B.y - A.y) + N.z * (B.z - A.z);
  vec3 result;
  result.x = (B.x - A.x) - 2.0 * dotResult * N.x;
  result.y = (B.y - A.y) - 2.0 * dotResult * N.y;
  result.z = (B.z - A.z) - 2.0 * dotResult * N.z;
  return result;
}

inline double pow2(double value)
{
  return value * value;
}

double getDistance(vec3 A, vec3 B)
{
  return sqrt(pow2(A.x - B.x) + pow2(A.y - B.y) + pow2(A.z - B.z));
}

vector<int> answer;
void Solve()
{
  answer.clear();
  int prev = -1;
  for(int T = -1; T < 15; T++)
  {
    if(answer.size() > 10)
    {
      break;
    }
    int current = -1;
    double currentT = 0;
    vec3 newStart;
    double l = finish.x - start.x,
      m = finish.y - start.y,
      p = finish.z - start.z;
    for(int i = 0; i < n; i++)
    {
      if(i == prev)
        continue;
      pair<double, double> tt = solveEquation(
        l * l + m * m + p * p,
        2 * l * (start.x - spheres[i].x) 
          + 2 * m * (start.y - spheres[i].y)
          + 2 * p * (start.z - spheres[i].z),
        pow2(start.x - spheres[i].x) + pow2(start.y - spheres[i].y)
          + pow2(start.z - spheres[i].z) - pow2(spheres[i].r));
      double t = 1e17;
      if(tt.first >= 0.0)
      {
        t = min(t, tt.first);
      }
      if(tt.second >= 0.0)
      {
        t = min(t, tt.second);
      }
      if(t != 1e17)
      {
        vec3 currentNewStart;
        currentNewStart.x = start.x + t * l;
        currentNewStart.y = start.y + t * m;
        currentNewStart.z = start.z + t * p;
        if((current == -1) ||
          (current != -1 && getDistance(start, currentNewStart) < getDistance(start, newStart) + eps))
        {
          current = i;
          currentT = t;
          newStart = currentNewStart;
        }
      }
    }
    if(current == -1)
    {
      break;
    }
    prev = current;
    finish = getReflection(start, newStart, current);
    finish.x += newStart.x;
    finish.y += newStart.y;
    finish.z += newStart.z;
    start = newStart;
    answer.push_back(current + 1);
  }
}

void WriteData()
{
  int cnt = min(10, (int)answer.size());
  for(int i = 0; i < cnt; i++)
  {
    printf("%d ", answer[i]);
  }
  if(answer.size() > 10)
    printf("etc.\n");
  else
  {
    printf("\n");
  }
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