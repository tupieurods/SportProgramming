#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
int table[509][509];

void ReadData()
{
  scanf("%d %d", &n, &m);
  memset(table, 0, sizeof(table));
  for(int row = 1; row <= n; row++)
  {
    for(int column = 1; column <= m; column++)
    {
      scanf("%d", &table[row][column]);
    }
  }
}

int aRow, aColumn;
int ans;

void Solve()
{
  ans = 0;
  aRow = 1;
  aColumn = 1;
  for(int row = 1; row <= n; row++)
  {
    for(int column = 1; column <= m; column++)
    {
      int current = table[row][column] * 8LL;
      for(int dx = -1; dx < 2; dx++)
      {
        for(int dy = -1; dy < 2; dy++)
        {
          if(dx == 0 && dy == 0)
          {
            continue;
          }
          current += table[row + dy][column + dx];
        }
      }
      if(current > ans)
      {
        ans = current;
        aRow = row;
        aColumn = column;
      }
    }
  }
}

void WriteData()
{
  printf("%d %d\n", aRow, aColumn);
}

//#define LOCAL

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n500 500\n");
    for(int i = 0; i < 500; i++)
    {
      for(int j = 0; j < 500; j++)
      {
        printf("10000000 ");
      }
      printf("\n");
    }
    return 0;
  }
  int QWE = 1;
  #ifdef LOCAL
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