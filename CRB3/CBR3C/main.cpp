#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

int field[3][3];

bool winChecker(int gamer)//gamer показывает по крестикам или по ноликам проверка
{
  for(int i = 0; i < 3; i++)
    {
      int sumX = 0;//по горизонтали
      int sumY = 0;//по вертикали
      for(int j = 0; j < 3; j++)
        {
          sumX += field[i][j];
          sumY += field[j][i];
        }
      if((sumX == gamer * 3) || (sumY == gamer * 3))
        return true;
    }
  //Главная диагональ
  if(field[0][0] + field[1][1] + field[2][2] == gamer * 3)
    return true;
  //Побочная диагональ
  if(field[0][2] + field[1][1] + field[2][0] == gamer * 3)
    return true;
  return false;
}

int main()
{
  int XCount = 0;
  int YCount = 0;
  for(int i = 0; i < 3; i++)
    {
      string line = "";
      getline(std::cin, line);
      for(int j = 0; j < 3; j++)
        {
          switch(line[j])
            {
              case '.':
                field[i][j] = 0;
                break;
              case 'X':
                field[i][j] = 1;
                XCount++;
                break;
              case '0':
                field[i][j] = 10;
                YCount++;
                break;
            }
        }
    }
  int difference = XCount - YCount;
  bool Xwon = winChecker(1);
  bool Ywon = winChecker(10);
  if((abs(difference) > 1)
      || (Xwon && Ywon)
      || ((XCount == 0) && (YCount != 0))
      || (Ywon && (XCount > YCount))
      || (Xwon && (YCount >= XCount))
      || (YCount > XCount))
    printf("illegal");
  else if((XCount + YCount == 9) && (!Xwon) && (!Ywon))
    printf("draw");
  else if(Xwon)
    printf("the first player won");
  else if(Ywon)
    printf("the second player won");
  else if((difference == 1) && (XCount + YCount != 9))
    printf("second");
  else if((difference == 0) && (XCount + YCount != 9))
    printf("first");
  return 0;
}
