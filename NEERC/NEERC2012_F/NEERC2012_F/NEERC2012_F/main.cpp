#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

//#define LOCALTEST
//#define SECTORDEBUG

char cube[5][5][5];
vector<int> sectorLens;

int startPos[6][3] = 
{
  //x y z
  {1, 3, 3}, {2, 1, 2}, {2, 1, 3},
  {2, 1, 2}, {2, 1, 3}, {2, 2, 2}
};

int delta[6][3] = 
{
  //x y z
  {0, -1, 0}, {0, 1, 0}, {0, 0, -1},
  {0, 0, 1}, {-1, 0, 0}, {1, 0, 0}
};
int directions[6] = {5, 4, 2, 0, 3, 1};

void ShowCube()
{
  for(int i = 3; i > 0; i--)
  {
    for(int j = 1; j < 4; j++)
    {
      for(int k = 3; k > 0; k--)
      {
        cout << cube[k][i][j];
      }
      if(j != 3)
        cout << " ";
    }
    cout << endl;
  }
}

void clearCube()
{
  for(int i = 3; i > 0; i--)
    for(int j = 1; j < 4; j++)
      for(int k = 3; k > 0; k--)
        cube[k][i][j] = '.';
}

char getNextInLine(char current)
{
  if(current > 'Z')
    return toupper(current + 1);
  else
    return tolower(current);
}

bool f(int x, int y, int z, int direction, int blockNumber, char prev)
{
  if(blockNumber == sectorLens.size())
    return true;

  static int PossibleDirections[6][4] = 
  {
    {1, 3, 4, 5},
    {0, 2, 4, 5},
    {1, 3, 4, 5},
    {0, 2, 4, 5},
    {0, 1, 2, 3},
    {0, 1, 2, 3}
  };
  //Четыре варианта вставить блок
  for(int i = 0; i < 4; i++)
  {
    bool flag = true;
    int dx = 0, dy = 0, dz = 0;
    //смещения для вставки блока
    switch(PossibleDirections[direction][i])
    {
    case 0:
      dz = 1;
      break;
    case 1:
      dx = 1;
      break;
    case 2:
      dz = -1;
      break;
    case 3:
      dx = -1;
      break;
    case 4:
      dy = 1;
      break;
    case 5:
      dy = -1;
      break;
    }
    //Пытаемся вставить блок
    int newZ = z, newY = y, newX = x;
    int installed = 0;
    char current = prev;
    for(int j = 1; j < sectorLens[blockNumber]; j++)
    {
      if(cube[newZ + dz][newY + dy][newX + dx] != '.')
      {
        flag = false;
        break;
      }
      current = getNextInLine(current);
      cube[newZ + dz][newY + dy][newX + dx] = current;
      newZ += dz;
      newY += dy;
      newX += dx;
      installed++;
    }
    //ShowCube();
    if(flag && f(newX, newY, newZ, PossibleDirections[direction][i], blockNumber + 1, current))
      return true;
    //Недопустимый ход, делаем как было и продолжаем
    dz = -dz;
    dy = -dy;
    dx = -dx;
    for(int j = installed; j > 0; j--)
    {
      cube[newZ][newY][newX] = '.';
      newZ += dz;
      newY += dy;
      newX += dx;
    }
    //ShowCube();
  }
  //Не вставили
  return false;
}

int FindInputDirection(string field[15], int x, int y)
{
  char next = getNextInLine(field[y][x]);
  if((y != 0) && (field[y - 1][x] != '.') && (field[y - 1][x] == next))
  {
    return 1;
  }
  else if((y != 14) && (field[y + 1][x] != '.') && (field[y + 1][x] == next))
  {
    return 3;
  }
  else if((x != 14) && (field[y][x + 1] != '.') && (field[y][x + 1] == next))
  {
    return 2;
  }
  else
  {
    return 4;
  }
}

//ОСТОРОЖНО! говнокод(
void calcLens(string field[15], int x, int y)
{
  char current = 'A';
  int direction = FindInputDirection(field, x, y);
  int len = 1;
  while(current != 'N')
  {
    switch(direction)
    {
    case 1:
      y--;
      break;
    case 2:
      x++;
      break;
    case 3:
      y++;
      break;
    case 4:
      x--;
      break;
    }
    //Вылезли за границы, меняем направление
    //Или след. символ херня
    if(((x == -1) || (x == 15) || (y == -1) || (y == 15)) || (field[y][x] != getNextInLine(current)))
    {
      switch(direction)
      {
      case 1:
        y++;
        break;
      case 2:
        x--;
        break;
      case 3:
        y--;
        break;
      case 4:
        x++;
        break;
      }
      sectorLens.push_back(len);
      len = 1;
      direction = FindInputDirection(field, x, y);
      continue;
    }
    current = field[y][x];
    len++;
  }
  sectorLens.push_back(len);
}

int main()
{
  freopen("folding.in", "r", stdin);
  freopen("folding.out", "w", stdout);
  int QWE;
#ifdef LOCALTEST
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    //Обнуляем куб
    for(int i = 0; i < 5; i++)
    {
      for(int j = 0; j < 5; j++)
      {
        for(int k = 0; k < 5; k++)
          if((i == 0) || (j == 0) || (k == 0)
            || (i == 4) || (j == 4) || (k == 4))
            cube[i][j][k] = '#';
          else
            cube[i][j][k] = '.';
      }
    }
    string field[15];
    int Ax = 0;
    int Ay = 0;
    for(int i = 0; i < 15; i++)
    {
      string str;
      cin >> str;
      field[i] = str;
      int pos = str.find("A");
      if(pos != -1)
      {
        Ay = i;
        Ax = pos;
      }
    }
    calcLens(field, Ax, Ay);
#ifdef SECTORDEBUG
    for(vector<int>::iterator it = sectorLens.begin(); it != sectorLens.end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
#endif
    int count = sectorLens[0] == 3 ? 3 : 6;
    char last = sectorLens[0] == 2 ? 'a' : 'B';
    int sectorLen = sectorLens[0];
    for(int i = 0; i < count; i++)
    {
      if(i >= 3)
      {
        last = 'a';
        sectorLen = 2;
      }
      char current = 'A';
      clearCube();
      int x = startPos[i][0] + (sectorLens[0] - 1) * delta[i][0],
        y = startPos[i][1] + (sectorLens[0] - 1) * delta[i][1],
        z = startPos[i][2] + (sectorLens[0] - 1) * delta[i][2];
      for(int j = 0; j < sectorLen; j++)
      {
        cube[startPos[i][2]][startPos[i][1]][startPos[i][0]] = current;
        current = getNextInLine(current);
        startPos[i][0] += delta[i][0];
        startPos[i][1] += delta[i][1];
        startPos[i][2] += delta[i][2];
      }
      if(f(x, y, z, directions[i], 1,last))
      {
        ShowCube();
        return 0;
      }
    }
  }
  return 0;
}