#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char matrix[9][8];

void ReadData()
{
  memset(matrix, 0, sizeof(matrix));
  char str[10];
  //printf("ReadData\n");
  for(int i = 0; i < 8; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < 8; j++)
    {
      matrix[0][i] <<= 1;
      if(str[j] == 'S')
        matrix[0][i] |= 1;
    }
    //printf("%d\n", (int)matrix[0][i]);
    //itoa(matrix[0][i], str, 2);
    //printf("%s\n", str);
  }
  //printf("\n");
}

bool answer;
int moves[9][2] =
{
  {0, 0},
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0},
  {1, 1},
  {-1, -1},
  {-1, 1},
  {1, -1}
};
char dp[10][10][10];

bool isBitOn(char val, int pos)
{
  return (val & (char)(1 << pos)) != 0;
}

bool f(int step, int y, int x)
{
  //printf("check: %d %d %d\n", step, y, x);
  if((y == 0 && x == 7) || step == 8)
    return true;
  if(dp[step][y][x] != -1)
  {
    return (bool)dp[step][y][x];
  }
  //region Не задавили ли статуи
  if(isBitOn(matrix[step][y], x))
  {
    return false;
  }
  //endregion Не задавили ли статуи
  char result = 0;
  //region Ходы
  for(int i = 0; i < 10; i++)
  {
    int newX = x + moves[i][0];
    int newY = y + moves[i][1];
    if(newX >= 0 && newY >= 0 && newX < 8 && newY < 8
      && !isBitOn(matrix[step][newY], newX))
    {
      if(f(step + 1, newY, newX))
      {
        result = 1;
        break;
      }
    }
  }
  //endregion Ходы
  dp[step][y][x] = result;
  return result;
}

void Solve()
{
  for(int i = 1; i < 9; i++)
  {
    for(int j = i; j < 8; j++)
    {
      matrix[i][j] = matrix[i - 1][j - 1];
    }
  }
  memset(dp, 0xFF, sizeof(dp));
  answer = false;
  answer = f(0, 7, 7);
}

void WriteData()
{
  if(answer)
    printf("WIN\n");
  else
    printf("LOSE\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}