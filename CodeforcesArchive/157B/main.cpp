#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int n;
int *a;

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

void ReadData()
{
  scanf("%d", &n);
  a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), compare);
}

double answer;

void Solve()
{
  answer = 0;
  int flag = 1;
  for(int i = 0; i < n; i++)
  {
    answer += flag * a[i] * a[i];
    flag = -flag;
  }
}

void WriteData()
{
  printf("%.10f\n", abs(answer * M_PI));
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
    Solve();
    WriteData();
  }
  return 0;
}