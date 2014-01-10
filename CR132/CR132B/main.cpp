#include <stdio.h>
#include <cmath>
#include <math.h>

using namespace std;

#define eps 1e-6

void getData(int *dataArray, int count)
{
  for(int i = 0; i < count; i++)
    {
      scanf("%d", &dataArray[i]);
    }
}

double inline max(double x, double y)
{
  return x - y > eps ? x : y;
}

int main()
{
  int n;
  scanf("%d", &n);
  int *x = new int[n];
  getData(x, n);
  int m;
  scanf("%d", &m);
  int *y = new int[m];
  getData(y, m);
  int k;
  scanf("%d", &k);
  int *z = new int[k];
  getData(z, k);
  int A, B;
  scanf("%d %d", &A, &B);
  double result = 0;
  double C = (double) A / B;
  int maxr = 0;
  for(int i = 0; i < n; i++)
    {
      if(x[i] > maxr)
        maxr = x[i];
    }
  //O(n^2)
  maxr = maxr * maxr;
  for(int j = 0; j < m; j++)
    {
      double tmp = (double)y[j] * maxr;
      for(int t = 0; t < k; t++)
        {
          result = max(result, tmp / ((double)C * z[t] + y[j]));
          //printf("p1=%d\tp2=%d\tsqrt(result)=%f\n",y[j],z[t],sqrt(result));
        }
    }
  printf("%f", sqrt(result));
  return 0;
}
