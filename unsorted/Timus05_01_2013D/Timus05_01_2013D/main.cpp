#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

//#define LOCALTEST

struct aim
{
  int x, y;
};

bool compare(aim a, aim b)
{
  if(a.y == b.y)
    return a.x < b.x;
  return a.y > b.y;
}

int main()
{
  #ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  #endif
  int QWE;
  #ifdef LOCALTEST
  scanf("%d\n", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d\n", &n);
    vector<aim> data;
    data.reserve(n);
    int minX = 0, minY = 0, maxX = 0, maxY = 0;
    for(int i = 0; i < n; i++)
    {
      int x, y;
      scanf("%d %d\n", &x, &y);
      aim tmp;
      tmp.x = x;
      tmp.y = y;
      data.push_back(tmp);
      minX = min(minX, x);
      minY = min(minY, y);
      maxX = max(maxX, x);
      maxY = max(maxY, y);
    }
    sort(data.begin(), data.end(), compare);
    int index = 0;
    for(int j = maxY; j >= minY; j--)
    {
      for(int i = minX; i <= maxX; i++)
      {
        if((data[index].x == i) && (data[index].y == j))
        {
          index++;
          printf("*");
          continue;
        }
        if((i == 0) && (j == 0))
        {
          printf("+");
        }
        else if(i == 0)
        {
          printf("|");
        }
        else if(j == 0)
        {
          printf("-");
        }
        else
        {
          printf(".");  
        }
      }
      printf("\n");
    }
  }
  return 0;
}