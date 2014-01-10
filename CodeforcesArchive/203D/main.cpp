#include <stdio.h>

int a, b, m;
double vX, vY, vZ;

void ReadData()
{
  scanf("%d %d %d", &a, &b, &m);
  scanf("%lf %lf %lf", &vX, &vY, &vZ);
}

double answerX, answerZ;

void Solve()
{
  double t;
  double x = (double)a / 2.0;
  double y = m;
  double z = 0;
  while(true)
  {
    if(y <= 1e-6)
    {
      answerX = x;
      answerZ = z;
      break;
    }
    //Право и лево выбраны так: Смотрим на дверь из точки m и бъём
    double top, down, door, right, left;
    //Потолок
    top = vZ > 0 ? ((double)b - z) / vZ : 1e6;
    //Пол
    down = vZ < 0 ? -z/ vZ : 1e6;
    //Дверь
    door = -y / vY;
    //Правая стена
    right = vX < 0 ? -x / vX : 1e6;
    //Левая стена
    left = vX > 0 ? ((double)a - x) / vX : 1e6;
    int flag = -1;
    double minimal = 1e6;
    if(top <= minimal)
    {
      flag = 0;
      minimal = top;
    }
    if(down <= minimal)
    {
      flag = 1;
      minimal = down;
    }
    if(right <= minimal)
    {
      flag = 3;
      minimal = right;
    }
    if(left <= minimal)
    {
      flag = 4;
      minimal = left;
    }
    if(door <= minimal)
    {
      flag = 2;
      minimal = door;
    }
    x = x + minimal * (double)vX;
    y = y + minimal * (double)vY;
    z = z + minimal * (double)vZ;
    switch(flag)
    {
      case 0:
      case 1:
        vZ *= -1;
        break;
      case 3:
      case 4:
        vX *= -1;
        break;
    }
  }
}


void WriteData()
{
  printf("%.10lf %.10lf\n", answerX, answerZ);
}

int main()
{
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
  }
  return 0;
}