#include <stdio.h>
#include <string.h>

int n;
double m;

void ReadData()
{
  scanf("%d %lf", &n, &m);
}

int *c;

void Solve()
{
  c = new int[n];
  memset(c, 0, sizeof(int) * n);
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    c[val - 1]++;
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%.2lf%%\n", (c[i] / m) * 100.0);
  }
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