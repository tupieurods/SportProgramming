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
int whiteCnt, blackCnt, maxSteps;
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
  for(int i = 0; i < blackCnt; i++)
  {
    scanf("%d %d", &p.x, &p.y);
    field[p.y][p.x] = BLACK;
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

bool check(int xVal, int yVal)
{
  return (xVal > 1) && (yVal > 1) && (xVal < n) && (yVal < n);
}

bool checkInside(int xVal, int yVal)
{
  return (xVal >= 1) && (yVal >= 1) && (xVal <= n) && (yVal <= n);
}

int f(int direction, int deep)
{
  if(deep >= blackCnt)
  {
    return 0;
  }
  //printf("king: %d %d\n", king.x, king.y);
  int result = 0;
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
      if(!check(nextP.x, nextP.y))//Если можем рубить в эту точку
      {
        break;
      }
      if(field[nextP.y][nextP.x] != 0)//Если в этой точке есть что рубить
      {
        if(field[nextP.y][nextP.x] == -BLACK)//Если шашка уже срублена
        {
          continue;
        }
        if(field[nextP.y][nextP.x] == BLACK)//Если это не белая шашка
        {
          for(int k = 1; k < maxSteps; k++)//Проверим куда сможем приземлиться после срубки
          {
            if(!checkInside(nextP.y + moves[i][0] * k, nextP.x + moves[i][1] * k)
              || field[nextP.y + moves[i][0] * k][nextP.x + moves[i][1] * k] != 0)
            {
              break;
            }
            field[nextP.y][nextP.x] = -BLACK;
            king.x = nextP.x + moves[i][1] * k;
            king.y = nextP.y + moves[i][0] * k;
            /*for(int deb = 0; deb < deep; deb++)
            {
              printf(" ");
            }
            printf("killed: %d %d. king: %d %d\n", nextP.x, nextP.y, king.x, king.y);*/
            result = std::max(result, 1 + f(i, deep + 1));
            answer = std::max(answer, result);
            if(answer == blackCnt)
            {
              return result;
            }
            field[nextP.y][nextP.x] = BLACK;
            king = copy;
          }
        }
        break;
      }
    }
  }
  return result;
}

void Solve()
{
  answer = f(4, 0);
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