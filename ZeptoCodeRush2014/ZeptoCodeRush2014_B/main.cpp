#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m, k;
char field[2009][2009];

void ReadData()
{
  scanf("%d %d %d%*c", &n, &m, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", field[i]);
  }
}

int answer[2009];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  for(int column = 0; column < m; column++)
  {
    for(int row = 1; row < n; row++)
    {
      int pos = row + row;
      if(pos < n && field[pos][column] == 'U')
      {
        answer[column]++;
      }
      pos = column + row;
      if(pos < m && field[row][pos] == 'L')
      {
        answer[column]++;
      }
      pos = column - row;
      if(pos >= 0 && field[row][pos] == 'R')
      {
        answer[column]++;
      }
    }
  }
}

void WriteData()
{
  for(int i = 0; i < m; i++)
  {
    printf("%d ", answer[i]);
  }
  printf("\n");
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