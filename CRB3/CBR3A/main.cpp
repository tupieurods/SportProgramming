#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int cache[9][9];
int FromX, FromY; //Координаты точки от которой мы идём
int ToX, ToY; //Координаты точки к которой мы идём

struct act
{
  int dx;
  int dy;
  string str;
};

act actions[8];

void ReadInput(int &x, int &y)
{
  string line;
  getline(std::cin, line);
  unsigned char tmp;
  sscanf(line.c_str(), "%c%d", &tmp, &y);
  x = (unsigned char)tmp - (unsigned char)'a' + 1;
}

int calcLength(int newX, int newY)
{
  if(cache[newX][newY] == -1)
    {
      int deltaX = abs(newX - ToX);
      int deltaY = abs(newY - ToY);
      cache[newX][newY] = abs(deltaX - deltaY) + min(deltaX, deltaY);
    }
  return cache[newX][newY];
}

bool InRange(int value, int bot = 1, int top = 8)
{
  return value >= bot && value <= top;
}

int main()
{
  ReadInput(FromX, FromY);
  ReadInput(ToX, ToY);
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      {
        cache[i][j] = -1;
      }
  actions[0] = {0, 1, "U"};
  actions[1] = {1, 1, "RU"};
  actions[2] = {1, 0, "R"};
  actions[3] = {1, -1, "RD"};
  actions[4] = {0, -1, "D"};
  actions[5] = { -1, -1, "LD"};
  actions[6] = { -1, 0, "L"};
  actions[7] = { -1, 1, "LU"};
  int count = 0;
  string result = "";
  while((FromY != ToY) || (FromX != ToX))
    {
      count++;
      int minLength = 100;
      int act = 0;
      for(int i = 0; i < 8; i++)
        {
          int newX = FromX + actions[i].dx;
          int newY = FromY + actions[i].dy;
          if(InRange(newX) && InRange(newY))
            {
              if(calcLength(newX, newY) < minLength)
                {
                  //Пользуемся знанием о том что вычисленные значения кешируются
                  //Чтобы не заводить ещё переменную
                  minLength = cache[newX][newY];
                  act = i;
                }
            }
        }
      FromX += actions[act].dx;
      FromY += actions[act].dy;
      result += actions[act].str + "\n";
    }
  printf("%d\n%s", count, result.c_str());
}
