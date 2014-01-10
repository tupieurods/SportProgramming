#include <stdio.h>
#include <math.h>

#define M_PI_2 1.57079632679489661923

struct vector3D
{
  double x, y, z;
};

int a[6];
vector3D viewPos;
vector3D coords;
vector3D normals[6];

void ReadData()
{
  scanf("%lf %lf %lf", &viewPos.x, &viewPos.y, &viewPos.z);
  scanf("%lf %lf %lf", &coords.x, &coords.y, &coords.z);
  for(int i = 0; i < 6; i++)
  {
    scanf("%d", &a[i]);
  }
}

double getLen(vector3D &vec)
{
  return abs(sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double getAngle(vector3D &vec1, vector3D &vec2)
{
  double result = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
  result /= getLen(vec1) * getLen(vec2);
  return result;
}

int answer;

void Solve()
{
  answer = 0;
  vector3D w;
  w.x = viewPos.x - coords.x / 2.0;
  w.y = viewPos.y;
  w.z = viewPos.z - coords.z / 2.0;
  if(acos(getAngle(normals[0], w)) < M_PI_2)
    answer += a[0];
  w.x = viewPos.x - coords.x / 2.0;
  w.y = viewPos.y - coords.y;
  w.z = viewPos.z - coords.z / 2.0;
  if(acos(getAngle(normals[1], w)) < M_PI_2)
    answer += a[1];

  w.x = viewPos.x - coords.x / 2.0;
  w.y = viewPos.y - coords.y / 2.0;
  w.z = viewPos.z;
  if(acos(getAngle(normals[2], w)) < M_PI_2)
    answer += a[2];
  w.x = viewPos.x - coords.x / 2.0;
  w.y = viewPos.y - coords.y / 2.0;
  w.z = viewPos.z - coords.z;
  if(acos(getAngle(normals[3], w)) < M_PI_2)
    answer += a[3];


  w.x = viewPos.x;
  w.y = viewPos.y - coords.y / 2.0;
  w.z = viewPos.z - coords.z / 2.0;
  if(acos(getAngle(normals[4], w)) < M_PI_2)
    answer += a[4];
  w.x = viewPos.x - coords.x;
  w.y = viewPos.y - coords.y / 2.0;
  w.z = viewPos.z - coords.z / 2.0;
  if(acos(getAngle(normals[5], w)) < M_PI_2)
    answer += a[5];
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  normals[0].x = 0, normals[0].y = -1, normals[0].z = 0;
  normals[1].x = 0, normals[1].y = 1, normals[1].z = 0;

  normals[2].x = 0, normals[2].y = 0, normals[2].z = -1;
  normals[3].x = 0, normals[3].y = 0, normals[3].z = 1;

  normals[4].x = -1, normals[4].y = 0, normals[4].z = 0;
  normals[5].x = 1, normals[5].y = 0, normals[5].z = 0;
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