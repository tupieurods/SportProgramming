#include <stdio.h>
#include <string.h>

int n, m;
int *rows, *columns;
int row, column;

void ReadData()
{
  scanf("%d %d%*c", &n, &m);
  rows = new int[n];
  columns = new int[m];
  memset(rows, 0, sizeof(int) * n);
  memset(columns, 0, sizeof(int) * m);
  char str[110];
  for(int i = 0; i < n; i++)
  {
    scanf("%s", str);
    for(int j = 0; j < m; j++)
    {
      if(str[j] == '*')
      {
        rows[i]++;
        columns[j]++;
      }
    }
    if(rows[i] == 1)
      row = i + 1;
  }
}

void Solve()
{
  for(int i = 0; i < m; i++)
  {
    if(columns[i] == 1)
    {
      column = i + 1;
      break;
    }
  }
}

void WriteData()
{
  printf("%d %d\n", row, column);
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