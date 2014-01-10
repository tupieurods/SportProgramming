#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m, xpos, ypos, a, b;

void ReadData()
{
  scanf("%d %d %d %d %d %d", &n, &m, &ypos, &xpos, &b, &a);
}

bool isInside(int xval, int yval)
{
  return (xval > 0 && yval > 0 && yval <= n && xval <= m);
}

int answer;

void Solve()
{
  answer = INT_MAX;
  int ends[4][2] = 
  {
    {1, 1},
    {n, 1},
    {1, m},
    {n, m},
  };
  for(int i = 0; i < 4; i++)
  {
    int dx = abs(xpos - ends[i][1]);
    int dy = abs(ypos - ends[i][0]);
    if(dx % a != 0 || dy % b != 0 || (dx / a) % 2 != (dy / b) % 2)
    {
      continue;
    }
    //Если число ходов неравное, то мы сможем пропрыгать недостающие вдоль одной из стенок
    //Но ходов будет максимум из необходимых по x и по y
    if(xpos != ends[i][1] && ypos != ends[i][0])
    {
      answer = min(answer, max(dx / a, dy / b));
      continue;
    }
    //Уже пришли
    if(xpos == ends[i][1] && ypos == ends[i][0])
    {
      answer = 0;
      return;
    }
    if(xpos == ends[i][1])
    {
      //Если можем прыгать от стенки и обратно
      if(isInside(xpos + a, ypos + b) || isInside(xpos - a, ypos + b) || isInside(xpos + a, ypos - b) || isInside(xpos - a, ypos - b))
      {
        answer = min(answer, dy / b);
      }
    }
    else if(ypos == ends[i][0])
    {
      //Если можем прыгать от стенки и обратно
      if(isInside(xpos + a, ypos + b) || isInside(xpos - a, ypos + b) || isInside(xpos + a, ypos - b) || isInside(xpos - a, ypos - b))
      {
        answer = min(answer, dx / a);
      }
    }
  }
}

void WriteData()
{
  if(answer == INT_MAX)
  {
    printf("Poor Inna and pony!\n");
  }
  else
  {
    printf("%d\n", answer);
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