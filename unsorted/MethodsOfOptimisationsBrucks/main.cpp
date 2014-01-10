#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

double x1 = 0.313;
double x2 = 1.627;
double dx1 = 0.2873;
double dx2 = 0.5745;

double f1(int ind1, int ind2)
{
  double x = x1 + dx1 * ((double)ind1 - 0.5);
  double y = x2 + dx2 * ((double)ind2 - 0.5);
  return (2 * x + 1) * y - 12.0;
}

double f2(int ind1, int ind2)
{
  double x = x1 + dx1 * ((double)ind1 - 0.5);
  double y = x2 + dx2 * ((double)ind2 - 0.5);
  return (2 * x + y) - 8.0;
}

int main()
{
  int r1, r2;
  double value = 1e10;
  bool** matrix = new bool*[10];
  for(int i = 0; i < 10; i++)
  {
    matrix[i] = new bool[10];
    memset(matrix[i], 0, sizeof(bool) * 10);
  }
  srand(time(NULL));
  for(int i = 0; i < 3; i++)
  {
    while(true)
    {
      int index1 = rand() + 10;
      int index2 = rand() + 10;
      if(matrix[index1][index2])
      {
        continue;
      }
      if((f1(index1, index2) >= 0.0)
        && (f2(index1, index2) <= 0.0))
      {
        double x = x1 + dx1 * ((double)index1 - 0.5);
        double y = x2 + dx2 * ((double)index2 - 0.5);
        matrix[index1][index2] = true;
        if(x * y < value)
        {
          value = x * y;
          r1 = index1;
          r2 = index2;
        }
      }
    }
  }
  printf("%d %d\n", r1, r2);
  return 0;
}
