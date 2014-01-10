#include <stdio.h>

struct point
{
  int x, y;
};

point p[3];
int moves[4][2] =
{
  {0, 1},
  {0, -1},
  {1, 0},
  {-1, 0}
};

void ReadData()
{
  for(int i = 0; i < 3; i++)
  {
    scanf("%d %d", &p[i].x, &p[i].y);
  }
}

bool validate(point &p1, point &p2, point &p3)
{
  return ((p1.x - p2.x) * (p3.y - p2.y) - (p1.y - p2.y) * (p3.x - p2.x)) != 0;
}

int distance(point &p1, point &p2)
{
  return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool pifagorValidate(point &p1, point &p2, point &p3)
{
  return distance(p1, p2) + distance(p1, p3) == distance(p2, p3);
}

int answer;

void Solve()
{
  if(pifagorValidate(p[0], p[1], p[2])
    || pifagorValidate(p[1], p[0], p[2])
    || pifagorValidate(p[2], p[0], p[1]))
  {
    answer = 1;
    return;
  }
  answer = 2;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      p[i].x += moves[j][0];
      p[i].y += moves[j][1];
      bool checker = validate(p[0], p[1], p[2]);
      bool checker2 = (pifagorValidate(p[0], p[1], p[2])
        || pifagorValidate(p[1], p[0], p[2])
        || pifagorValidate(p[2], p[0], p[1]));
      if(validate(p[0], p[1], p[2])
        && (pifagorValidate(p[0], p[1], p[2])
        || pifagorValidate(p[1], p[0], p[2])
        || pifagorValidate(p[2], p[0], p[1])))
      {
        return;
      }
      p[i].x -= moves[j][0];
      p[i].y -= moves[j][1];
    }
  }
  answer = 3;
}

void WriteData()
{
  switch(answer)
  {
  case 1:
    printf("RIGHT\n");
    break;
  case 2:
    printf("ALMOST\n");
    break;
  case 3:
    printf("NEITHER\n");
    break;
  default:
    throw;
  }
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