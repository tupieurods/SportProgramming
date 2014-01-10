#include <stdio.h>
#include <stdlib.h>

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int n, m;
int c[9], a[1009], b[1009];

void ReadData()
{
  for(int i = 0; i < 4; i++)
  {
    scanf("%d", &c[i]);
  }
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }
}

int answer;

void Solve()
{
  answer = min(c[3], c[2] * 2);
  int currentA = 0;
  for(int i = 0; i < n; i++)
  {
    currentA += min(c[0] * a[i], c[1]);
  }
  int currentB = 0;
  for(int i = 0; i < m; i++)
  {
    currentB += min(c[0] * b[i], c[1]);
  }
  answer = min(answer, min(currentA + currentB, min(c[2] + currentA, c[2] + currentB)));
}

void WriteData()
{
  printf("%d\n", answer);
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
