#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define LOCALTEST

int** field;
int** leftPathField;
int** rightPathField;
int w, h;
int directions[4][3] =
{
  {0, -1, 2},//Up
  {1, 0, 3},//Right
  {0, 1, 0},//Down
  {-1, 0, 1},//Left
};

bool check(int x, int y, int direction)
{
  x += directions[direction][0];
  y += directions[direction][1];
  if((x >= 0) && (y >= 0) 
    && (x < w) && (y < h)
    && (field[y][x] == 0))
    return true;
  return false;
}

inline int getRight(int direction)
{
  direction++;
  return direction == 4 ? 0 : direction;
}

inline int getLeft(int direction)
{
  direction--;
  return direction == -1 ? 3 : direction;
}

inline int getBack(int direction)
{
  return directions[direction][2];
}

void findRightPath()
{
  rightPathField[0][0] = 1;
  int posX = 0, posY = 0;
  int direction = 1;
  while(!((posX == (w - 1)) && (posY == (h - 1))))
  {
    direction = getRight(direction);
    while(!check(posX, posY, direction))
    {
      direction--;
      if(direction == -1)
        direction = 3;
    }
    posX += directions[direction][0];
    posY += directions[direction][1];
    rightPathField[posY][posX] = 1;
  }
}

void findLeftPath()
{
  leftPathField[0][0] = 1;
  int posX = 0, posY = 0;
  int direction = 1;
  while(!((posX == (w - 1)) && (posY == (h - 1))))
  {
    direction = getLeft(direction);
    while(!check(posX, posY, direction))
    {
      direction++;
      if(direction == 4)
        direction = 0;
    }
    posX += directions[direction][0];
    posY += directions[direction][1];
    leftPathField[posY][posX] = 1;
  }
}

inline int getArrayValue(int** arr, int x, int y)
{
  if(!((x >= 0) && (y >= 0) && (x < w) && (y < h)))
    return 0;
  return arr[y][x];
}

void calcMapSums(int** arr)
{
  for(int i = 0; i < h; i++)
  {
    for(int j = 0; j < w; j++)
    {
      arr[i][j] = arr[i][j] + getArrayValue(arr, j - 1, i) 
        + getArrayValue(arr, j, i - 1) - getArrayValue(arr, j - 1, i - 1);
    }
  }
}

int getSum(int** arr, int x1, int y1, int x2, int y2)
{
  return getArrayValue(arr, x2, y2) - getArrayValue(arr, x1 - 1, y2) 
        - getArrayValue(arr, x2, y1 - 1) + getArrayValue(arr, x1 - 1, y1 - 1);
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d\n", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d %d\n", &w, &h);
    field = new int*[h];
    leftPathField = new int*[h];
    rightPathField = new int*[h];
    for(int i = 0; i < h; i++)
    {
      char c;
      field[i] = new int[w];
      leftPathField[i] = new int[w];
      rightPathField[i] = new int[w];
      for(int j = 0; j < w; j++)
      {
        scanf("%c", &c);
        field[i][j] = c == '.' ? 0 : 1;
        leftPathField[i][j] = 0;
        rightPathField[i][j] = 0;
      }
      scanf("\n", &c);
    }
    findRightPath();
    calcMapSums(rightPathField);
    findLeftPath();
    calcMapSums(leftPathField);
    calcMapSums(field);
    int resultX = 0, resultY = 0, anwser = 2000;
    for(int i = 0; i < h; i++)
    {
      for(int j = 0; j < w; j++)
      {
        if(((i == 0) && (j == 0)) || ((i == h - 1) && (j == w - 1)))
          continue;
        int top = min(w - j, h - i);
        for(int k = 0; k < top; k++)
        {
          if((getSum(field, j, i, j + k, i + k) == 0)
            && (getSum(rightPathField, j, i, j + k, i + k) > 0)
            && (getSum(leftPathField, j, i, j + k, i + k) > 0)
            && (k < anwser))
          {
            anwser = k;
            resultX = j;
            resultY = i;
          }
        }
      }
    }
    if(anwser == 2000)
    {
      printf("Impossible\n");
    }
    else
    {
      printf("%d %d %d\n", anwser + 1, resultX + 1, resultY + 1);
    }
  }
  return 0;
}