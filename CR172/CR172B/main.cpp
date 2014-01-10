#include <stdio.h>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
  double x, y, n;
  scanf("%lf %lf %lf", &x, &y, &n);
  double b, a;
  double currentDelta = 1e300;
  for(int i = 1; i <= n; i++)
  {
    double tmp = round((x / y) * (double)i);
    if(abs(x/y - tmp / (double)(i)) < currentDelta)
    {
      if(abs(currentDelta - 0.16667) < 1e-3)
        continue;
      currentDelta = abs(x/y - tmp / (double)(i));
      a = tmp;
      b = i;
      if(tmp > 0 && abs(x/y - (tmp - 1) / (double)(i)) <= currentDelta)
      {
        currentDelta = abs(x/y - (tmp - 1) / (double)(i));
        a = tmp - 1;
        b = i;
      }
    }
  }
  printf("%d/%d", (int)a, (int)b);
  return 0;
}
