#include <stdio.h>
#include <limits.h>
#include <cstdlib>

using namespace std;

struct point
{
  int x;
  int y;
};

int **field;
int ***cache;
int n;
int maxD;
int HalfMaxD;

int inline GetMax(int d)
{
  return (d) > HalfMaxD ? n - 1 : (d);
}

int inline GetMin(int d)
{
  return (d) > HalfMaxD ? (d) - HalfMaxD : 0;
}

int inline max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int f(int d, int x1, int x2)
{
  if(d == maxD)
    return field[n-1][n-1];
  int XminFirst = GetMin(d);
  if(cache[d][x1-XminFirst][x2-XminFirst] == INT_MIN + 1)
    {
      int result;
      if(x1 == x2)
        result = field[d-x1][x1];
      else
        result = field[d-x1][x1] + field[d-x2][x2];
      int results[4] = {INT_MIN,INT_MIN,INT_MIN,INT_MIN};
      int Xmin = GetMin(d + 1);
      int Xmax = GetMax(d + 1);
      if(d - x1 != n - 1
        && d - x2 != n - 1)
        results[0] = f(d + 1, x1, x2);
      if((x1 + 1 >= Xmin && x1 + 1 <= Xmax)
        && (x2 + 1 >= Xmin && x2 + 1 <= Xmax))
        results[1] = f(d + 1, x1 + 1, x2 + 1);
      if((x1 + 1 >= Xmin && x1 + 1 <= Xmax)
        && (x2 >= Xmin&& x2 <= Xmax))
        results[2] = f(d + 1, x1 + 1, x2);
      if((x1 >= Xmin && x1 <= Xmax)
        && (x2 + 1 >= Xmin&& x2 + 1 <= Xmax))
        results[3] = f(d + 1, x1, x2 + 1);
        /*printf("d=%d\n",d);
        for(int i=0; i<4; i++)
        printf("result[%d]=%d\n",i,results[i]);*/
      int maximum = max(results[0], max(results[1], max(results[2], results[3])));
      cache[d][x1-XminFirst][x2-XminFirst] = maximum + result;
    }
  return cache[d][x1-XminFirst][x2-XminFirst];
}

int main()
{
  scanf("%d", &n);
  int tmp;
  if(n == 1)
    {
      scanf("%d", &tmp);
      printf("%d", tmp);
      return 0;
    }
  maxD = n * 2 - 2;
  HalfMaxD = maxD / 2;
  {
    cache = new int**[maxD+1];
    for(int d = 0; d <= maxD; d++)
      {
        int min = GetMin(d);
        int max = GetMax(d);
        cache[d] = new int*[max - min+1];
        //printf("d=%d\tmin=%d\tmax=%d\n",d,min,max);
        for(int x1 = min; x1 <= max; x1++)
          {
            cache[d][x1-min] = new int[max - min+1];
            for(int x2 = min; x2 <= max; x2++)
              {
                cache[d][x1-min][x2-min] = INT_MIN + 1;
              }
          }
      }
  }
  field = new int*[n];
  for(int i = 0; i < n; i++)
    {
      field[i] = new int[n];
      for(int j = 0; j < n; j++)
        {
          scanf("%d", &tmp);
          field[i][j] = tmp;
        }
    }
  int count = f(0, 0, 0);
  printf("%d", count);
  return 0;
}
