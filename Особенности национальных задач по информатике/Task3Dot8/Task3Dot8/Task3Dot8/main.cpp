#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <string.h>

using namespace std;

//#define LOCALTEST

int vertices[8855];
int previous[8855];
map<int, int*> states;
int* w;

struct point
{
  int x, y;
};

point from, to;

int directions[4][2] = 
{
  {0, 1},//Up
  {1, 0},//right
  {0, -1},//down
  {-1, 0},//left
};

int friends[6][4] =
{
  {3, 4, 2, 5},
  {2, 4, 3, 5},
  {0, 4, 1, 5},
  {1, 4, 0, 5},
  {3, 1, 2, 0},
  {1, 3, 0, 2}
};

void showPoint(int x, int y)
{
  printf("%c%d ", (char)('a' + x - 1), y);
}

inline int getHashCode(int down, int front)
{
  return down * 10 + front;
}

void parseVertex(int vertex, int &front, int &down, int &x, int &y)
{
  front = vertex % 10;
  vertex /= 10;
  down = vertex % 10;
  vertex /= 10;
  y = vertex % 10;
  vertex /= 10;
  x = vertex % 10;
}

inline int getVertex(int x, int y, int down, int front)
{
  return x * 1000 + y * 100 + getHashCode(down, front);
}

inline int getOpposite(int value)
{
  return value ^ 1;
}

bool compare(int a, int b)
{
  if(vertices[a] == vertices[b])
    return a < b;
  return vertices[a] < vertices[b];
}

void generateStates(int down, int front)
{
  if(states.count(getHashCode(down, front)) != 0)
    return;
  //{Вверх. Вправо. Вниз. Влево}
  int* currentDirections = new int[4];
  //Ищем позицию фронтальной грани
  int index = 0;
  for(int i = 0; i < 4; i++)
  {
    if(friends[down][i] == front)
    {
      index = i;
      break;
    }
  }
  int delta = 2 - index + 4;
  for(int i = 0; i < 4; i++)
  {
    currentDirections[(i + delta) % 4] = friends[down][i];
  }
  //Запомнили возможные ходы
  states.insert(make_pair(getHashCode(down, front), currentDirections));
  //Поехали
  //Вверх
  generateStates(currentDirections[0], down);
  //Вправо
  generateStates(currentDirections[1], front);
  //Вниз
  generateStates(currentDirections[2], getOpposite(down));
  //Влево
  generateStates(currentDirections[3], front);
}

void relax(int from, int to, int w)
{
  if(vertices[from] + w < vertices[to])
  {
    previous[to] = from;
    vertices[to] = vertices[from] + w;
  }
}

bool check(int x, int y, int dx, int dy)
{
  x += dx;
  y += dy;
  if(x >= 1 && y >= 1 && x <= 8 && y <= 8)
    return true;
  return false;
}

inline void gotoVertex(set<int, bool(*)(int, int)> &Q, set<int> &anwser, int currentVertex, int* gotoStates, int x, int y, int direction, int newFront)
{
  int stateCode = getVertex(x + directions[direction][0], y + directions[direction][1], gotoStates[direction], newFront);
  if(check(x, y, directions[direction][0], directions[direction][1]) 
    && anwser.count(stateCode)==0)
  {
    Q.erase(stateCode);
    //relax
    relax(currentVertex, stateCode, w[gotoStates[direction]]);
    //add to set
    Q.insert(stateCode);
  }
}

void showWay(int state)
{
  if(state != getVertex(from.x, from.y, 3, 0))
  {
    showWay(previous[state]);
  }
  showPoint((state / 1000), (state / 100) % 10);
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
  generateStates(3, 0);
  //printf("%d\n", states.size());
  for(int T = 0; T < QWE; T++)
  {
    char str[3];
    scanf("%s", &str);
    from.x = str[0] - 'a' + 1;
    from.y = str[1] - '0';
    scanf("%s", &str);
    to.x = str[0] - 'a' + 1;
    to.y = str[1] - '0';
    w = new int[6];
    scanf("%d", &w[0]);
    scanf("%d", &w[1]);
    scanf("%d", &w[2]);
    scanf("%d", &w[4]);
    scanf("%d", &w[3]);
    scanf("%d", &w[5]);
    memset(vertices, 0x7F, sizeof(int) * 8855);
    memset(previous, 0x7F, sizeof(int) * 8855);
    set<int, bool(*)(int, int)> Q(compare);
    set<int> anwser;
    vertices[getVertex(from.x, from.y, 3, 0)] = w[3];
    previous[getVertex(from.x, from.y, 3, 0)] = getVertex(from.x, from.y, 3, 0);
    Q.insert(getVertex(from.x, from.y, 3, 0));
    while(!Q.empty())
    {
      //Получить минимум
      int current = *Q.begin();
      Q.erase(current);
      anwser.insert(current);
      //Пройтись по всем рёбрам из текущей вершине
      int currentFront, currentDown, x, y;
      parseVertex(current, currentFront, currentDown, x, y);
      int* gotoStates = states[current % 100];
      //{Вверх. Вправо. Вниз. Влево};
      //Вверх
      gotoVertex(Q, anwser, current, gotoStates, x, y, 0, currentDown);
      //Вправо
      gotoVertex(Q, anwser, current, gotoStates, x, y, 1, currentFront);
      //Вниз
      gotoVertex(Q, anwser, current, gotoStates, x, y, 2, getOpposite(currentDown));
      //Влево
      gotoVertex(Q, anwser, current, gotoStates, x, y, 3, currentFront);
    }
    int minimalWay = 0x7F7F7F7F;
    int prev = 0;
    for(int i = 0; i < 6; i++)
    {
      for(int j = 0; j < 6; j++)
      {
        //printf("%d %d\n", vertices[getVertex(to.x, to.y, i, j)], getVertex(to.x, to.y, i, j));
        if(vertices[getVertex(to.x, to.y, i, j)] < minimalWay)
        {
          minimalWay = vertices[getVertex(to.x, to.y, i, j)];
          prev = getVertex(to.x, to.y, i, j);
        }
      }
    }
    printf("%d ", minimalWay);
    showWay(prev);
    printf("\n");
  }
  return 0;
}