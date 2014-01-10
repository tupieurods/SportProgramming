#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int matrix[15][15];
int w[15][256][15][15][2][2], p[15][256][15][15][2][2];
int n, m, k, answer;
int bestX, bestY, bestL, bestR;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int f(int h, int t, int i, int j, int l, int r)
{
  int xPos = l == 1 ? i : j;
  int value = matrix[h][xPos];
  if(t == k)
  {
    return 0;
  }
  /*for(int tt = 0; tt < t; tt++)
  {
    printf("|");
  }
  printf("h: %d t: %d i: %d j: %d l: %d r: %d\n", h, t, i, j, l, r);*/
  if(w[h][t][i][j][l][r] != -1)
  {
    return w[h][t][i][j][l][r];
  }
  //Если число клеток до конца поля меньше чем нам надо, выходим
  if((n - (h + 1)) * m + (l == 1 ? i + 1 : m - (j + 1)) <= k - t)
    return -1;
  int result = -1, bestMove = -1;
  int nextH, nextI, nextJ, nextL, nextR;
  if(l == 1)//Можем двигаться только влево и вниз
  {
    //Пробуем пойти влево
    nextH = h, nextI = i - 1, nextJ = j, nextL = l, nextR = r;
    if(nextI == -1)
    {
      nextH = h + 1, nextI = 0, nextJ = 0, nextL = 0, nextR = 1;
    }
    if(nextH != n)
    {
      result = f(nextH, t + 1, nextI, nextJ, nextL, nextR);
      if(result != -1)
      {
        bestMove = 0;
      }
    }
  }
  else//Можем двигаться только вправо и вниз
  {
    //Пробуем пойти вправо
    nextH = h, nextI = i, nextJ = j + 1, nextL = l, nextR = r;
    if(nextJ == m)
    {
      nextH = h + 1, nextI = m - 1, nextJ = m - 1, nextL = 1, nextR = 0;
    }
    if(nextH != n)
    {
      result = f(nextH, t + 1, nextI, nextJ, nextL, nextR);
      if(result != -1)
      {
        bestMove = 0;
      }
    }
  }
  if(nextH != n)
  {
    //Пробуем пойти вниз
    nextH = h + 1, nextI = i, nextJ = j, nextL = r, nextR = l;
    if(l == 1)
      nextJ = i;
    else
      nextI = j;
    int tmp = f(nextH, t + 1, nextI, nextJ, nextL, nextR);
    if(tmp > result)
    {
      bestMove = 1;
      result = tmp;
    }
  }
  if(bestMove != -1)
  {
    w[h][t][i][j][l][r] = result + value;
    p[h][t][i][j][l][r] = result == 0 ? -2 : bestMove;
    return result + value;
  }
  return -1;
}

void Solve()
{
  memset(w, 0xFF, sizeof(w));
  memset(p, 0xFF, sizeof(p));
  bestX = 0, bestY = 0 , bestL = 0, bestR = 0;
  answer = -2;
  int tmp;
  //answer = f(0, 0, 0, 0, 0, 1);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      tmp = f(i, 0, j, j, 0, 1);
      if(tmp > answer)
      {
        answer = tmp, bestY = i, bestX = j, bestL = 0, bestR = 1;
      }
      tmp = f(i, 0, j, j, 1, 0);
      if(tmp > answer)
      {
        answer = tmp, bestY = i, bestX = j, bestL = 1, bestR = 0;
      }
    }
  }
}

void WriteData()
{
  printf("Oil : %d\n", answer);
  //printf("h: %d t: %d i: %d j: %d l: %d r: %d\n", bestY, 0, bestX, bestX, bestL, bestR);
  /*int t = 0;
  int i = bestX, j = bestX;
  while(t != k)
  {
    printf("h: %d t: %d i: %d j: %d l: %d r: %d\n", bestY, t, i, j, bestL, bestR);
    if(p[bestY][t][i][j][bestL][bestR] == -1)
      throw "mistake";
    //int nextH, nextI, nextJ, nextL, nextR;
    if(p[bestY][t][i][j][bestL][bestR] == 0)
    {
      if(bestL == 1)//Можем двигаться только влево и вниз
      {
        //Пробуем пойти влево
        bestY = bestY, i = i - 1, j = j, bestL = bestL, bestR = bestR;
        if(i == -1)
        {
          bestY = bestY + 1, i = 0, j = 0, bestL = 0, bestR = 1;
        }
      }
      else//Можем двигаться только вправо и вниз
      {
        //Пробуем пойти вправо
        bestY = bestY, i = i, j = j + 1, bestL = bestL, bestR = bestR;
        if(j == m)
        {
          bestY = bestY + 1, i = m - 1, j = m - 1, bestL = 1, bestR = 0;
        }
      }
    }
    else if(p[bestY][t][i][j][bestL][bestR] == 1)
    {
      bestY = bestY + 1, i = i, j = j, bestL = bestL, bestR = bestR;
    }
    else
    {
      throw "another mistake";
    }
    t++;
  }*/
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
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