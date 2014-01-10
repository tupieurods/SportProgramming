#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[8][8][2];
int x_[2], y_[2];
char table[8][15];

void ReadData()
{
  memset(a, 0, sizeof(a));
  x_[0] = -1;
  for(int i = 0; i < 8; i++)
  {
    scanf("%s%*c", table[i]);
    for(int j = 0; j < 8; j++)
    {
      if(table[i][j] == 'K')
      {
        if(x_[0] == -1)
        {
          x_[0] = j;
          y_[0] = i;
        }
        else
        {
          x_[1] = j;
          y_[1] = i;
        }
      }
    }
  }
}

bool answer;

void Solve()
{
  answer = false;
  for(int T = 0; T < 2; T++)
  {
    for(int dy = -4; dy < 4; dy++)
    {
      int y_pos = y_[T] + 4 * dy;
      if(y_pos < 0 || y_pos > 7)
      {
        continue;
      }
      for(int dx = -4; dx < 4; dx++)
      {
        int x_pos = x_[T] + 4 * dx;
        if(x_pos < 0 || x_pos > 7)
        {
          continue;
        }
        a[y_pos][x_pos][T] = 1;
      }
    }
    for(int y_pos = y_[T] - 10; y_pos < 8; y_pos += 4)
    {
      if(y_pos < 0 || y_pos > 7)
      {
        continue;
      }
      for(int x_pos = x_[T] - 10; x_pos < 8; x_pos += 4)
      {
        if(x_pos < 0 || x_pos > 7)
        {
          continue;
        }
        a[y_pos][x_pos][T] = 2;
      }
    }
  }
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(a[i][j][0] != 0 && a[i][j][1] != 0
        && a[i][j][1] == a[i][j][0] && table[i][j] != '#')
      {
        answer = true;
        return;
      }
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}

int main()
{
  int QWE = 0;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d%*c", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}