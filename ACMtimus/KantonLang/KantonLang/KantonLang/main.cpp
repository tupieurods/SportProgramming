#include <stdio.h>

int n, m, N, M;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &N);
}

void Solve()
{
  double p = 0.0;
  for(int i = m; i <= N - n; i++)
  {
    double t = ((double)(n - m) / (double)(N - i)) * (double)m / i;
    if(((double)(n - m) / (double)(N - i))
      * (double)m / i > p)
    {
      p = ((double)(n - m) / (double)(N - i)) * (double)m / i;
      M = i;
    }
  }
}

void WriteData()
{
  printf("%d", M);
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