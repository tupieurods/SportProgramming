#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int n, m;

void ReadData()
{
  scanf("%d %d", &m, &n);
}

double answer;

void Solve()
{
  answer = 0;
  for(int i = 1; i <= m; i++)
  {
    answer += i * (pow((1.0 * i) / m, n) - pow((i - 1.0) / m, n));
  }
}

void WriteData()
{
  printf("%.20lf\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}