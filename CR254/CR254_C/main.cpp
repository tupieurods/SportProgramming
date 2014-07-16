#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
int xval[509];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &xval[i]);
  }
}

double answer;

void Solve()
{
  answer = 0.0;
  for(int i = 0; i < m; i++)
  {
    int from, to, w;
    scanf("%d %d %d", &from, &to, &w);
    from--;
    to--;
    answer = std::max(answer, (1.0 *(xval[from] + xval[to])) / w);
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