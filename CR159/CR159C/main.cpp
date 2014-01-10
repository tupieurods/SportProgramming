#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct point
{
  int x, y;
};

int compare(const void* a, const void* b)
{
  return (*(double*)a - *(double*)b > 0 ? 1 : -1);
}

int main()
{
  int n;
  scanf("%d\n", &n);
  point* arr = new point[n];
  double* angles = new double[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &arr[i].x, &arr[i].y);
    angles[i] = atan2((double)arr[i].y, (double)arr[i].x);
  }
  qsort(angles, n, sizeof(double), compare);
  double anwser = 0.0;
  for(int i = 1; i < n; i++)
  {
    anwser = max(anwser, angles[i] - angles[i - 1]);
  }
  //Если появляется ситуация
  //Когда все точки на одном луче
  //Мы получили бы 2pi, а в результате правильный угол, равный нулю
  anwser = max(anwser, angles[0] - angles[n - 1] + 2 * M_PI);
  printf("%.50lf", 360 - anwser * 180 / M_PI);
  return 0;
}
/*
8
0 1
1 1
1 0
1 -1
0 -1
-1 -1
-1 0
-1 1
*/
/*
8
0 2
1 1
2 0
1 -1
0 -2
-1 -1
-2 0
-1 1
*/
