#include <stdio.h>
#include <string.h>

int a, b;
char str[105];
int dx, dy;

/*
-1 -1
UR
*///Проверка на mul>=0

void ReadData()
{
  scanf("%d %d%*c", &a, &b);
  scanf("%s", &str);
}

bool answer;

inline int abs(int val)
{
  return val < 0 ? -val : val;
}

void Solve()
{
  answer = true;
  if(a == 0 && b == 0)
    return;
  int n = strlen(str);
  dx = 0, dy = 0;
  for(int i = 0; i < n; i++)
  {
    if(str[i] == 'R')
      dx++;
    if(str[i] == 'L')
      dx--;
    if(str[i] == 'U')
      dy++;
    if(str[i] == 'D')
      dy--;
  }
  int currentX = 0, currentY = 0;
  for(int i = 0; i < n; i++)
  {
    if(currentX == a && currentY == b)
    {
      return;
    }
    if(dx != 0 && (a - currentX) % dx == 0)
    {
      int mul = (a - currentX) / dx;
      if(currentX + dx * mul == a
        && currentY + dy * mul == b && mul >=0)
        return;
    }
    if(dy != 0 && (b - currentX) % dy == 0)
    {
      int mul = (b - currentY) / dy;
      if(currentX + dx * mul == a
        && currentY + dy * mul == b && mul >=0)
        return;
    }
    if(str[i] == 'R')
      currentX++;
    if(str[i] == 'L')
      currentX--;
    if(str[i] == 'U')
      currentY++;
    if(str[i] == 'D')
      currentY--;
  }
  answer = false;
}

void WriteData()
{
  if(answer)
    printf("Yes\n");
  else
    printf("No\n");
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