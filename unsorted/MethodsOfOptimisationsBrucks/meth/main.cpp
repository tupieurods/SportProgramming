#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double x1 = 0.313;//0.313;
double x2 = 1.627;//6.223;//1.627;
double dx1 = 0.2873;//0.2873 / 10.0;//0.2873;
double dx2 = 0.5745;//(7.372 - x2) / 10.0;//0.5745;

double f1(int ind1, int ind2)
{
  double x = x1 + dx1 * ((double)ind1 + 0.5);
  double y = x2 + dx2 * ((double)ind2 + 0.5);
  return (2 * x + 1) * y - 12.0;
}

double f2(int ind1, int ind2)
{
  double x = x1 + dx1 * ((double)ind1 + 0.5);
  double y = x2 + dx2 * ((double)ind2 + 0.5);
  return 2 * x + y - 8.0;
}

int main()
{
  int r1 = -1, r2 = -1;
  double value = 1e10;
  bool** matrix = new bool*[10];
  for(int i = 0; i < 10; i++)
  {
    matrix[i] = new bool[10];
    memset(matrix[i], 0, sizeof(bool) * 10);
  }
  srand(time(NULL));
  for(int i = 0; i < 44; i++)
  {
    int index1 = rand() % 10;
    int index2 = rand() % 10;
    if(matrix[index1][index2])
    {
      continue;
    }
    matrix[index1][index2] = true;
    if((f1(index1, index2) >= 0.0)
      && (f2(index1, index2) <= 0.0))
    {
      double x = x1 + dx1 * ((double)index1 + 0.5);
      double y = x2 + dx2 * ((double)index2 + 0.5);
      if(x * y < value)
      {
        printf("%f %f\n", value, x * y);
        value = x * y;
        r1 = index1;
        r2 = index2;
      }
    }
  }
  //r1 = 0, r2 = 9;
  double x = x1 + dx1 * ((double)r1);
  double y = x2 + dx2 * ((double)r2);
  printf("%d %d\n", r1, r2);
  printf("%f %f\n", x, y);
  return 0;
}
