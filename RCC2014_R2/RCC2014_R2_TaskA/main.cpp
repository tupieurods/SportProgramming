#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m, p, q, t;

void ReadData()
{
  scanf("%d %d %d %d %d", &n, &m, &p, &q, &t);
}

int answer;

void Solve()
{
  answer = INT_MAX;
  int a = std::min(t / p, n);
  int b = std::min((t - a * p) / q, m);
  int soloN = t / p;
  int soloM = t / q;
  for(int i = 0; i < t + 10; i++)
  {
    int current = 1;
    int n1 = std::max(0, n - a);
    int m1 = std::max(0, m - b);
    current += n1 / soloN + (n1 % soloN == 0 ? 0 : 1);
    current += m1 / soloM + (m1 % soloM == 0 ? 0 : 1);
    answer = std::min(answer, current);
    a = std::max(a - 1, 0);
    b = std::min((t - a * p) / q, m);
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

//#define LOCAL

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}