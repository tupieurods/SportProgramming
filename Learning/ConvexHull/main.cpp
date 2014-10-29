#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct point
{
  int x, y;
};

int n;
point *p;

void ReadData()
{
  scanf("%d", &n);
  p = new point[n];
  int idx = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &p[i].x, &p[i].y);
    if(p[i].y < p[idx].y || (p[i].y == p[idx].y && p[i].x < p[idx].x))
    {
      idx = i;
    }
  }
  swap(p[0], p[idx]);
}

int *stack;
int stackCnt;

int crossProduct(point &p1, point &p2, point &pBase)
{
  int x1 = p1.x - pBase.x;
  int x2 = p2.x - pBase.x;
  int y1 = p1.y - pBase.y;
  int y2 = p2.y - pBase.y;
  return x1 * y2 - x2 * y1;
}

bool comparer(point p1, point p2)
{
  return crossProduct(p1, p2, p[0]) > 0;
}

void Solve()
{
  stack = new int[n];
  stackCnt = 0;
  sort(p + 1, p + n, comparer);
  /*for(int i = 0; i < n; i++)
  {
    printf("%d %d\n", p[i].x, p[i].y);
  }
  printf("stage 1 done!");*/
  stackCnt = 3;
  stack[0] = 0;
  stack[1] = 1;
  stack[2] = 2;
  for(int i = 3; i < n; i++)
  {
    while(true)
    {
      if(stackCnt == 2)
      {
        break;
      }
      int Sign = crossProduct(p[i], p[stack[stackCnt - 1]], p[stack[stackCnt - 2]]);
      if(Sign < 0)
      {
        break;
      }
      stackCnt--;
    }
    stack[stackCnt] = i;
    stackCnt++;
  }
}

void WriteData()
{
  for(int i = 0; i < stackCnt; i++)
  {
    printf("%d %d\n", p[stack[i]].x, p[stack[i]].y);
  }
  printf("\n");
}

int main()
{
  freopen("input.txt", "r", stdin);
  ReadData();
  Solve();
  WriteData();
  return 0;
}