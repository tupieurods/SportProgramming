#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;

int table[109][10009];

void ReadData()
{
  scanf("%d %d", &n, &m);
}

int answer[2][10009];

void Solve()
{
  int xVal = 10000;
  for(int i = n; i > 0; i--)
  {
    answer[0][i - 1] = table[i][xVal];
    xVal -= table[i][xVal] * table[i][xVal];
  }
  xVal = 10000;
  for(int i = m; i > 0; i--)
  {
    answer[1][i - 1] = table[i][xVal];
    xVal -= table[i][xVal] * table[i][xVal];
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      printf("%d ", answer[0][i] * answer[1][j]);
    }
    printf("\n");
  }
}

void precalc()
{
  memset(table, 0xFF, sizeof(table));
  table[0][0] = 0;
  for(int i = 1; i < 103; i++)
  {
    for(int j = 10003; j >= 0; j--)
    {
      if(table[i - 1][j] != -1)
      {
        for(int t = 1; t <= 100; t++)
        {
          if(t * t + j < 10003)
          {
            table[i][t * t + j] = t;
          }
        }
      }
    }
  }
}

int main()
{
  precalc();
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