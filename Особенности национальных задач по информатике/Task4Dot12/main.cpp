#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct vertex
{
  int x, y;
  int parent_id;

  vertex& operator =(int val)
  {
    x = val;
    y = val;
    parent_id = val;
    return *this;
  }
};

int n, verticiesCount;
double w[129];
bool used[129];
pair<int, int> quads[39];
vertex verticies[129];

void Add(int x, int y)
{
  if(x + y == 0 || x + y == 200)
  {
    return;
  }
  verticies[verticiesCount].x = x;
  verticies[verticiesCount].y = y;
  verticiesCount++;
}

void ReadData()
{
  memset(used, 0, sizeof(used));
  for(int i = 0; i < 129; i++)
  {
    verticies[i] = -1;
    w[i] = 1e10;
  }
  verticiesCount = 1;
  verticies[0].x = 0;
  verticies[0].y = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    quads[i].first = x;
    quads[i].second = y;
    Add(x, y);
    Add(x + 5, y);
    Add(x, y + 5);
    Add(x + 5, y + 5);
  }
  verticies[verticiesCount].x = 100;
  verticies[verticiesCount].y = 100;
  verticiesCount++;
}

int cross(int x1, int y1, int x2, int y2, int x3, int y3)
{
  int x1p = x2 - x1;
  int x2p = x3 - x1;
  int y1p = y2 - y1;
  int y2p = y3 - y1;
  return x1p * y2p - x2p * y1p;
}

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  //Координаты ограничивающих прямоугольников
  int x1p = min(x1, x2);
  int x2p = max(x1, x2);
  int y1p = min(y1, y2);
  int y2p = max(y1, y2);
  int x3p = min(x3, x4);
  int x4p = max(x3, x4);
  int y3p = min(y3, y4);
  int y4p = max(y3, y4);
  if(!(x1p <= x4p && x2p >= x3p
      && y1p <= y4p && y2p >= y3p))
  {
    return false;
  }
  return cross(x1, y1, x2, y2, x3, y3) * cross(x1, y1, x2, y2, x4, y4) < 0
    && cross(x3, y3, x4, y4, x1, y1) * cross(x3, y3, x4, y4, x2, y2) < 0;
}

double pow2(int val)
{
  return val * val;
}

//Проверка, принадлежит ли точка прямой, заданной уравнение Ax+By+C=0
bool checkDotOnLine(int A, int B, int C, int xPos, int yPos)
{
  return (A * xPos + B * yPos + C) == 0;
}

bool inRange(int l, int r, int val)
{
  return val >= l && val <= r;
}

bool checkDiagonal(int id1, int id2, int quad)
{
  int x1p = min(verticies[id1].x, verticies[id2].x);
  int x2p = max(verticies[id1].x, verticies[id2].x);
  int y1p = min(verticies[id1].y, verticies[id2].y);
  int y2p = max(verticies[id1].y, verticies[id2].y);
  int A = verticies[id2].y - verticies[id1].y;
  int B = verticies[id1].x - verticies[id2].x;
  int C = -verticies[id1].x * A - verticies[id1].y * B;
  if(checkDotOnLine(A, B, C, quads[quad].first, quads[quad].second)
      && checkDotOnLine(A, B, C, quads[quad].first + 5, quads[quad].second + 5)
      && inRange(x1p, x2p, quads[quad].first)
      && inRange(x1p, x2p, quads[quad].first + 5)
      && inRange(y1p, y2p, quads[quad].second)
      && inRange(y1p, y2p, quads[quad].second + 5))
    return true;
  if(checkDotOnLine(A, B, C, quads[quad].first + 5, quads[quad].second)
      && checkDotOnLine(A, B, C, quads[quad].first, quads[quad].second + 5)
      && inRange(x1p, x2p, quads[quad].first)
      && inRange(x1p, x2p, quads[quad].first + 5)
      && inRange(y1p, y2p, quads[quad].second)
      && inRange(y1p, y2p, quads[quad].second + 5))
    return true;
  return false;
  /*return 
  ((checkDotOnLine(A, B, C, quads[quad].first, quads[quad].second)
      && checkDotOnLine(A, B, C, quads[quad].first + 5, quads[quad].second + 5))
  || (checkDotOnLine(A, B, C, quads[quad].first + 5, quads[quad].second)
      && checkDotOnLine(A, B, C, quads[quad].first, quads[quad].second + 5)));*/
}

void Solve()
{
  w[0] = 0;
  for(int T = 0; T < verticiesCount; T++)
  {
    int index = -1;
    for(int i = 0; i < verticiesCount; i++)
    {
      if(used[i])
      {
        continue;
      }
      if((index == -1 && w[i] != 1e10)
        || (index != -1 && w[i] < w[index]))
      {
        index = i;
      }
    }
    if(index == -1 || index == (verticiesCount - 1))
    {
      break;
    }
    used[index] = true;
    /*if(index == 43)
    {
      printf("hi\n");
    }*/
    for(int i = 0; i < verticiesCount; i++)
    {
      if(used[i])
      {
        continue;
      }
      bool flag = true;
      for(int j = 0; j < n; j++)
      {
        if(check(quads[j].first, quads[j].second, quads[j].first + 5, quads[j].second,
                verticies[index].x, verticies[index].y, verticies[i].x, verticies[i].y)

          || check(quads[j].first, quads[j].second, quads[j].first, quads[j].second + 5,
                verticies[index].x, verticies[index].y, verticies[i].x, verticies[i].y)

          || check(quads[j].first + 5, quads[j].second, quads[j].first + 5, quads[j].second + 5,
                verticies[index].x, verticies[index].y, verticies[i].x, verticies[i].y)

          || check(quads[j].first, quads[j].second + 5, quads[j].first + 5, quads[j].second + 5,
                verticies[index].x, verticies[index].y, verticies[i].x, verticies[i].y))
        {
          flag = false;
          break;
        }
        if(checkDiagonal(index, i, j))
        {
          flag = false;
          break;
        }
        /*printf("debug: %d %d %d %d\n", verticies[index].x, verticies[index].y,
          verticies[i].x, verticies[i].y);*/
      }
      if(flag)
      {
        double newVal = w[index] + sqrt(pow2(verticies[i].x - verticies[index].x)
                        + pow2(verticies[i].y - verticies[index].y));
        if(newVal < w[i])
        {
          w[i] = newVal;
          verticies[i].parent_id = index;
        }
      }
    }
  }
}

vector<int> answer;

void g(int index)
{
  if(index != 0)
  {
    g(verticies[index].parent_id);
  }
  answer.push_back(index);
  //printf("%d %d\n", verticies[index].x, verticies[index].y);
}

void WriteData()
{
  answer.clear();
  g(verticiesCount - 1);
  //int prevVertex = -1, prevPrevVertex = -1;
  for(int i = 0; i < answer.size(); i++)
  {
    if(i < 1 || i == answer.size() - 1 || cross(verticies[answer[i - 1]].x, verticies[answer[i - 1]].y, 
      verticies[answer[i]].x, verticies[answer[i]].y,
      verticies[answer[i + 1]].x, verticies[answer[i + 1]].y) != 0)
    printf("%d %d\n", verticies[answer[i]].x, verticies[answer[i]].y);
  }
  //printf("%.5lf next\n", w[verticiesCount - 1]);
}

int main()
{
  int QWE = 0;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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