#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define M_PI 3.14159265358979323846

struct point2f
{
  double x, y;
};

int n, l;
point2f input[1009];
int a[1009];

double vectorMul(point2f &p1, point2f &p2, point2f &p3)
{
  return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

inline double dist(point2f &p1, point2f &p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

/*double getArcLen(point2f &p1, point2f &p2, point2f &p3)
{
  point2f n1;
  n1.x = p2.y - p1.y;
  n1.y = p1.x - p2.x;
  point2f n2;
  n2.x = p2.y - p3.y;
  n2.y = p3.x - p2.x;
  double phi = (n1.x * n2.x + n1.y * n2.y) 
    / (sqrt((n1.x * n1.x + n1.y * n1.y) * (n2.x * n2.x + n2.y * n2.y)));
  double res = acos(abs(phi)) * l;
} */

double getArcLen(point2f &p1, point2f &p2, point2f &p3)
{
  point2f n1;
  n1.x = p2.y - p1.y;
  n1.y = p2.x - p1.x;
  point2f n2;
  n2.x = p2.y - p3.y;
  n2.y = p2.x - p3.x;
  double phi = (n1.x * n2.x + n1.y * n2.y) 
    / (sqrt((n1.x * n1.x + n1.y * n1.y) * (n2.x * n2.x + n2.y * n2.y)));
  double tmp = M_PI - acos(phi);
  //printf("%.5lf\n", tmp);
  /*if(tmp == M_PI)
    tmp = 0;*/
  return tmp * l;
}

int comparer(const void *v1, const void *v2)
{
  int res = -(int)vectorMul(input[a[0]], input[*(int*)v1], input[*(int*)v2]);
  /*if(res == 0 && input[*(int*)v2].y == input[*(int*)v1].y)
  {
    return input[*(int*)v1].x - input[*(int*)v2].x;
  }*/
  if(res == 0)
  {
    return (int)(dist(input[a[0]], input[*(int*)v1]) - dist(input[a[0]], input[*(int*)v2]));
  }
  return res;
}

void ReadData()
{
  scanf("%d %d", &n, &l);
  for(int i = 0; i < n; i++)
  {
    scanf("%lf %lf", &input[i].x, &input[i].y);
    a[i] = i;
  }
}

double answer;

void Solve()
{
  //Выбираем левую нижнюю точку:
  int best = 0;
  for(int i = 0; i < n; i++)
  {
    if(input[i].y < input[best].y
      || (input[i].y == input[best].y && input[i].x < input[best].x))
    /*if(input[i].x < input[best].x
      || (input[i].x == input[best].x && input[i].y < input[best].y))*/
    {
      best = i;
    }
  }
  //printf("%lf\n", vectorMul(input[8], input[5], input[3]));
  //Сортируем по полярному углу
  a[best] = 0;
  a[0] = best;
  qsort(a + 1, n - 1, sizeof(int), comparer);
  vector<int> b;
  b.push_back(a[0]);
  for(int i = 1; i < n;)
  {
    int j = i + 1;
    int toAdd = a[i];
    /*while(j < n && vectorMul(input[a[0]], input[a[i]], input[a[j]]) == 0)
    {
      if(dist(input[a[0]], input[toAdd]) < dist(input[a[0]], input[a[j]]))
      {
        toAdd = a[j];
      }
      j++;
    }*/
    i = j;
    b.push_back(toAdd);
  }
 /* for(int i = 0; i < n; i++)
  {
    printf("%d: %0.lf %0.lf\n", a[i], input[a[i]].x, input[a[i]].y);
  } */
  /*return;*/
  vector<int> convexHull;
  convexHull.push_back(b[0]);
  convexHull.push_back(b[1]);
  int cnt = 2;
  int bSize = b.size();
  for(int i = 2; i < bSize; i++)
  {
    while(/*cnt > 2 && */vectorMul(input[convexHull[cnt - 2]], 
      input[convexHull[cnt - 1]], input[b[i]]) < 0)
    {
      convexHull.pop_back();
      cnt--;
    }
    convexHull.push_back(b[i]);
    cnt++;
  }
  /*printf("convex hull\n");
  for(int i = 0; i < cnt; i++)
  {
    printf("%d: %0.lf %0.lf\n", convexHull[i], input[convexHull[i]].x, input[convexHull[i]].y);
  } */
  /*convexHull.push_back(a[0]);
  cnt++;*/
  answer = 0.0;
  //Длины сторон
  for(int i = 0; i < cnt - 1; i++)
  {
    answer += sqrt(dist(input[convexHull[i]], input[convexHull[i + 1]]));
  }
  //Замыкающая сторона
  answer += sqrt(dist(input[a[0]], input[convexHull[cnt - 1]]));
  //Длины дуг
  for(int i = 0; i < cnt - 2; i++)
  {
    answer += getArcLen(input[convexHull[i]],
      input[convexHull[i + 1]], input[convexHull[i + 2]]);
  }
  //Предпоследняя дуга
  answer += getArcLen(input[convexHull[cnt - 2]],
      input[convexHull[cnt - 1]], input[convexHull[0]]);
  //Замыкающая дуга
  answer += getArcLen(input[convexHull[cnt - 1]],
      input[convexHull[0]], input[convexHull[1]]);
}

void WriteData()
{
  int answer_i = (int)answer;
  if(answer - answer_i > 0.5)
  {
    answer_i++;
  }
  printf("%d\n", answer_i);
}

int main()
{
  int QWE = 16;
  freopen("wall.out", "w", stdout);
  #ifndef LOCAL
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    string testFileName = "wall.";
    if(T + 1 < 10)
    {
      testFileName += "0";
      testFileName += ((char)(T + 1) + '0');
    }
    else
    {
      testFileName += ((char)((T + 1) / 10) + '0');
      testFileName += ((char)((T + 1) % 10) + '0');
    }
    freopen(testFileName.c_str(), "r", stdin);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}