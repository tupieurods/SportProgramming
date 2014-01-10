#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char used[10][10], mines[10][10];
int numbers[10][10];
bool showMines;

void ReadData()
{
  scanf("%d", &n);
  memset(used, 0, sizeof(used));
  memset(mines, 0, sizeof(mines));
  memset(numbers, 0, sizeof(numbers));
  showMines = false;
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", mines[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", used[i]);
    for(int j = 0; j < n; j++)
    {
      if(used[i][j] == 'x' && mines[i][j] == '*')
      {
        showMines = true;
      }
    }
  }
}

int getVal(int y, int x)
{
  if(y < 0 || x < 0 || y >= n || x >= n)
  {
    return 0;
  }
  return mines[y][x] == '*';
}

int moves[8][2] =
{
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0},
  {-1, 1},
  {1, -1},
  {1, 1},
  {-1, -1},
};

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < 8; k++)
      {
        numbers[i][j] += getVal(i + moves[k][0], j + moves[k][1]);
      }
    }
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(showMines && mines[i][j] == '*')
      {
        printf("*");
        continue;
      }
      if(used[i][j] == 'x')
      {
        printf("%d", numbers[i][j]);
      }
      else
      {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main()
{
  //freopen("input.txt", "r", stdin);
  ReadData();
  Solve();
  WriteData();
  return 0;
}