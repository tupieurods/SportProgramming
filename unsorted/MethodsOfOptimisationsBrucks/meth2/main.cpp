#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double x1 =0.62003;// 0.341730;
double x2 = 5.643;//7.14220;

double f1(double x, double y)
{
  return (2 * x + 1) * y - 12.0;
}

double f2(double x, double y)
{
  return 2 * x + y - 8.0;
}

int main()
{
  double arr[2] = {x1, x2};
  double h = 0.01;
  double f[5] = {0.0, 0.0, 0.0, 0.0, 0.0};
  double delta[4][2] = 
  {
    {-h, 0.0},
    {h, 0.0},
    {0.0, -h},
    {0.0, h},
  };
  bool flag = true;
  int iter = 0;
  while(true)
  { 
    iter++;
    f[0] = arr[0] * arr[1];
    printf("initial: %f\n", f[0]);
    int ind = 0;
    int from, to;
    if(flag)
    {
      from = 1;
      to = 3;
    }
    else
    {
      from = 3;
      to = 5;
    }
    flag = !flag;
    for(int i = from; i < to; i++)
    {
      f[i] = (arr[0] + delta[i - 1][0]) * (arr[1] + delta[i - 1][1]);
      //printf("value[%d]: %f\n", i, f[i]);
      if((f[ind] > f[i])
          /*&& ((f1(arr[0] + delta[i - 1][0], arr[1] + delta[i - 1][1]) >= 0.0) 
          && (f2(arr[0] + delta[i - 1][0], arr[1] + delta[i - 1][1]) <= 0.0))*/
        )
      {
        
        ind = i;
      }
    }
    if(ind != 0)
    {
      for(int i = 0; i < 2; i++)
      {
        arr[i] += delta[ind - 1][i];
        printf("x[%d] = %f\n", i, arr[i]);
      }
    }
    printf("iteration: %d value: %f\n", iter, f[ind]);
    system("PAUSE");
  }
  return 0;
}
