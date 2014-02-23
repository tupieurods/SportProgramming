#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

struct point2d
{
  int x, y;
};

#define WHITE 1
#define BLACK 2

int n;
point2d king;
int whiteCnt, blackCnt, blackCntToKill, maxSteps;
int field[29][29];

void ReadData()
{
  scanf("%d", &n);
  maxSteps = n * 2;
  scanf("%d %d", &king.x, &king.y);
  scanf("%d", &whiteCnt);
  point2d p;
  memset(field, 0, sizeof(field));
  for(int i = 0; i < whiteCnt; i++)
  {
    scanf("%d %d", &p.x, &p.y);
    field[p.y][p.x] = WHITE;
  }
  scanf("%d", &blackCnt);
  blackCntToKill = blackCnt;
  for(int i = 0; i < blackCnt; i++)
  {
    scanf("%d %d", &p.x, &p.y);
    field[p.y][p.x] = BLACK;
    if(p.x == 1 || p.x == n || p.y == 1 || p.y == n)
    {
      blackCntToKill--;
    }
  }
}

int moves[4][2] =
{
  {1, 1},
  {-1, -1},
  {-1, 1},
  {1, -1}
};

int bad[5] = {1, 0, 3, 2, 100500};

int answer;

inline bool check(int xVal, int yVal)
{
  return (xVal > 1) && (yVal > 1) && (xVal < n) && (yVal < n);
}

inline bool checkInside(int xVal, int yVal)
{
  return (xVal >= 1) && (yVal >= 1) && (xVal <= n) && (yVal <= n);
}

void f(int direction, int killed)
{
  if(killed > answer)
  {
    answer = killed;
    //printf("%d\n", answer);
  }
  if(answer >= blackCntToKill)
  {
    return;
  }
  //int result = 0;
  point2d copy = king;
  for(int i = 0; i < 4; i++)
  {
    if(bad[direction] == i)
    {
      continue;
    }
    for(int j = 1; j < maxSteps; j++)
    {
      point2d nextP = {king.x + moves[i][1] * j, king.y + moves[i][0] * j};
      if(!check(nextP.x, nextP.y) || field[nextP.y][nextP.x] == WHITE)
      {
        break;
      }
      if(field[nextP.y][nextP.x] == BLACK)
      {
        point2d afterBlack = nextP;
        for(int k = 1; k < maxSteps; k++)
        {
          afterBlack.y += moves[i][0];
          afterBlack.x += moves[i][1];
          if(!checkInside(afterBlack.y, afterBlack.x) || field[afterBlack.y][afterBlack.x] != 0)
          {
            break;
          }
          field[nextP.y][nextP.x] = 0;
          king = afterBlack;
          f(i, 1 + killed);
          //result = std::max(result, 1 + f(i, 1 + killed));
          field[nextP.y][nextP.x] = BLACK;
          king = copy;
        }
        break;
      }
    }
  }
  //return result;
}

void Solve()
{
  f(4, 0);
}

void WriteData()
{
  printf("%d\n", answer);
}

void show()
{
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(i == king.y && j == king.x)
      {
        printf("K");
      }
      else if(field[i][j] == BLACK)
      {
        printf("B");
      }
      else if(field[i][j] == WHITE)
      {
        printf("W");
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
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n20\n");
    printf("11 10\n");
    printf("1\n2 1\n");
    printf("99\n");
    int check = 0;
    for(int i = 1; i <= 20; i++)
    {
      for(int j = 1; j <= 20; j++)
      {
        if(i != 2 || j != 1)
        {
          if((i % 2 == 0 && j % 2 == 1)) //|| (i % 2 == 1 && j % 2 == 0))
          {
            printf("%d %d\n", i, j);
            check++;
          }
        }
      }
    }
    printf("checker: %d\n", check);
    return 0;
  }
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
    //show();
  }
  return 0;
}