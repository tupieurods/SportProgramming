#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

#define LOCALTEST

using namespace std;

struct point
{
  float x, y;
};

point getPoint(float x, float y)
{
  point* result = (point*)malloc(sizeof(point));
  result->x = x;
  result->y = y;
  return *result;
}

bool compare(int a, int b);

int N, I, S;
float verticies[1021];
int previous[1021];
float** wMatrix;
point* data;
point zeroPoint;
point leftN;
point rightN;
set<int, bool(*)(int, int)> Q(compare);
set<int, bool(*)(int, int)>::iterator it;
set<int> anwser;

int getHash(int hillNumber, int revNumber)
{
  return hillNumber * 100 + revNumber;
}

bool compare(int a, int b)
{
  if(verticies[a] == verticies[b])
    return a < b;
  return verticies[a] < verticies[b];
}

//проверяет что точка C слева от вектора AB
bool leftDotFromVect(point A, point B, point C)
{
  return ((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)) > 0;
}

bool noTail(point B)
{
  return leftDotFromVect(zeroPoint, rightN, B) 
    && !leftDotFromVect(zeroPoint, leftN, B);
}

  void relax(int from, int to)
{
  if(anwser.find(to) != anwser.end())
    return;
  float w = verticies[from] + wMatrix[from / 100][to / 100];
  if(w < verticies[to])
  {
    it = Q.find(to);
    if(it != Q.end())
    {
      Q.erase(it);
    }
    verticies[to] = w;
    previous[to] = from;
    Q.insert(to);
  }
}

void printAnwser(int curr)
{
  if(previous[curr] != curr)
    printAnwser(previous[curr]);
  printf("%d ", (curr / 100) + 1);
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  zeroPoint = getPoint(0, 0);
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d %d %d", &N, &I, &S);
    data = new point[N];
    for(int i = 0; i < N; i++)
    {
      scanf("%f %f", &data[i].x, &data[i].y);
    }
    wMatrix = new float*[N];
    memset(verticies, 0x7F, sizeof(int) * 1021);
    memset(previous, 0, sizeof(int) * 1021);
    for(int i = 0; i < N; i++)
    {
      wMatrix[i] = new float[N];
      for(int j = 0; j < N; j++)
      {
        scanf("%f", &wMatrix[i][j]);
      }
    }
    I += 10;
    S--;
    //Поставил стартовую точку в первую координатную четверть
    while(true)
    {
      if(data[S].x >= 0 && data[S].y >= 0)
        break;
      for(int i = 0; i < N; i++)
      {
        swap(data[i].x, data[i].y);
        data[i].y = -data[i].y;
      }
    }
    leftN.x = -data[S].y;
    leftN.y = data[S].x;
    rightN.x = data[S].y;
    rightN.y = -data[S].x;
    Q.insert(getHash(S, I));
    verticies[getHash(S, I)] = 0;
    previous[getHash(S, I)] = getHash(S, I);
    while(!Q.empty())
    {
      int current = *Q.begin();
      anwser.insert(current);
      int turn = current % 100;
      int pos = current / 100;
      //printf("Debug: pos:%d turn:%d\n", pos, turn);
      Q.erase(Q.begin());
      bool fromPos = leftDotFromVect(zeroPoint, data[S], data[pos]);
      for(int i = 0; i < N; i++)
      {
        if(pos == i)//Не будем сами к себе прыгать
          continue;
        bool toPos = leftDotFromVect(zeroPoint, data[S], data[i]);
        int toRelax = i * 100;
        if(pos == S)//Если топаем из стартовой точки
        {
          if(toPos)
          {
            toRelax += turn;
          }
          else
          {
            if(turn == 20)
              continue;
            toRelax += turn + 1;
          }
        }
        else
        {
          if(i == S)//Если топаем в стартовую точку
          {
            if(fromPos)
            {
              toRelax += turn;
            }
            else
            {
              if(turn == 0)
                continue;
              toRelax += turn - 1;
            }
          }
          else
          {
            if(!noTail(data[i]) || !noTail(data[pos]))
            {
              toRelax += turn;
            }
            else
            {
              if(fromPos)//Идём слева
              {
                if(toPos)
                {
                  toRelax += turn;
                }
                else
                {
                  if(turn == 20)
                    continue;
                  toRelax += turn + 1;
                }
              }
              else//Идём справа
              {
                if(toPos)
                {
                  if(turn == 0)
                    continue;
                  toRelax += turn - 1;
                }
                else
                {
                  toRelax += turn;
                }
              }
            }
          }
        }
        relax(current, toRelax);
      }
    }
    printf("%.10f\n", verticies[getHash(S, 10)]);
    printAnwser(getHash(S, 10));
    anwser.clear();
    printf("\n");
  }
  return 0;
}