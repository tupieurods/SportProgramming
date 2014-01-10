#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int Tx, Ty;
  scanf("%d %d", &Tx, &Ty);
  if(Tx == 0 && Ty == 0)
  {
    printf("0");
    return 0;
  }
  int answer = 0;
  int x = 0, y = 0, i = 1;
  int prevX = 0, prevY = 0;
  int delta = 0;
  int crapX = 1, crapY = 1;
  while(true)
  {
    /*printf("x: %d y: %d\n", x, y);
    system("PAUSE");*/
    if((i % 2) == 1)
    {
      delta++;
    }
    i++;
    if(x == Tx)
    {
      if(((prevY >= 0) && (Ty <= prevY && Ty >= y))
        ||((prevY <= 0) && (Ty >= prevY && Ty <= y)))
        break;
    }
    if(y == Ty)
    {
      if(((prevX >= 0) && (Tx <= prevX && Tx >= x))
        ||((prevX <= 0) && (Tx >= prevX && Tx <= x)))
        break;
    }
    prevX = x;
    prevY = y;
    if((i % 2) == 1)
    {
      y += delta * crapY;
      crapY = -crapY;
    }
    else
    {
      x += delta * crapX;
      crapX = -crapX;
    }
    answer++;
  }
  printf("%d", answer - 1);
  return 0;
}
