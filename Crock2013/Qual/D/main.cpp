#include <stdio.h>
#include <stdlib.h>

int n, k;

void ReadData()
{
  scanf("%d %d", &n, &k);
}

void SolveAndWrite()
{
  int *a = new int[n];
  int *result = new int[n];
  for(int i = 0; i < n; i++)
  {
    a[i] = 1;
    result[i] = n - i - 1;
  }
  a[n - 1] = 0;
  int maximal = 1;
  for(int step = 1; step <= k; step++)
  {
    for(int i = 0; i < n; i++)
    {
      int delta = result[i] - a[i];
      if(delta > 0)
      {
        if(delta > maximal)
        {
          printf("%d ", n - maximal);
          a[i] += maximal;
        }
        else
        {
          printf("%d ", n - delta);
          a[i] += delta;
        }
      }
      else
      {
        printf("%d ", n);
      }
    }
    maximal *= 2;
    printf("\n");
  }
  if(a[0] != n - 1)
    throw "wrong solution";
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    SolveAndWrite();
    //WriteData();
  }
  return 0;
}