#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[509][509];
int n, m, s, x_pos, y_pos;

void ReadData()
{
  scanf("%d %d %d%*c", &n, &m, &s);
  memset(input, 0, sizeof(input));
  x_pos = 509, y_pos = 509;
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", input[i]);
    for(int j = 0; j < m; j++)
    {
      if(input[i][j] != '.')
      {
        continue;
      }
      if(x_pos > j)
      {
        x_pos = j;
        y_pos = i;
      }
    }
  }
}

int moves[4][2] = 
{
  {0, 1},
  {1, 0},
  {-1, 0},
  {0, -1}
};
bool colors[509][509];

bool canMove(int newY, int newX)
{
  return (newY >= 0 && newX >= 0 && newX < m && newY < n 
    && colors[newY][newX] == false && input[newY][newX] == '.');
}

void dfsVisit(int newY, int newX)
{
  if(colors[newY][newX])
  {
    throw;
  }
  colors[newY][newX] = true;
  for(int i = 0; i < 4; i++)
  {
    bool test = canMove(newY + moves[i][0], newX + moves[i][1]);
    if(test)
    {
      dfsVisit(newY + moves[i][0], newX + moves[i][1]);
    }
  }
  if(s != 0)
  {
    s--;
    input[newY][newX] = 'X';
  }
}

void Solve()//dfs
{
  memset(colors, 0, sizeof(colors));
  dfsVisit(y_pos, x_pos);
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", input[i]);
  }
  printf("\n");
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