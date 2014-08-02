#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char matrix[109][109];
int n;

void ReadData()
{
  scanf("%d", &n);
}

void Solve()
{
  memset(matrix, 0, sizeof(matrix));
  int c = n / 2;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      matrix[i][j] = i == c ? 'D' : '*';
    }
  }
  int add = 0;
  for(int i = 0; i < c; i++)
  {
    matrix[i][c] = 'D';
    for(int j = 0; j <= add; j++)
    {
      matrix[i][c - j] = matrix[i][c + j] = 'D';
      matrix[n - i - 1][c - j] = matrix[n - i - 1][c + j] = 'D';
    }
    add++;
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", matrix[i]);
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