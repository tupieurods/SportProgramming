#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <map>
#include <ctime>
#include <iostream>

#pragma comment(linker, "/STACK:15000000")

#define LOCALTEST

using namespace std;

//int count1;
map<__int64, pair<__int64, int>> bfsResult;

int directions[9][4] = 
{
  {1, 3, -1, -1},//from 0
  {0, 4, 2, -1},//from 1
  {1, 5, -1, -1},//from 2
  {0, 4, 6, -1},//from 3
  {1, 3, 5, 7},//from 4
  {2, 4, 8, -1},//from 5
  {3, 7, -1, -1},//from 6
  {6, 4, 8, -1},//from 7
  {7, 5, -1, -1}//from 8
};

//Медленно(
int get9Pos(__int64 value)
{
  int pos = 8;
  while((value % 10) != 9)
  {
    value /= 10;
    pos--;
  }
  return pos;
}

//Тоже не быстро
__int64 SwapDigits(__int64 value, int pos1, int pos2)
{
  static int digits[9];
  static __int64 powersOf10[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
  /*pos1 = 8 - pos1;
  pos2 = 8 - pos2;*/
  for(int i = 8; i >= 0; i--)
  {
    digits[i] = value % 10;
    value /= 10;
  }
  swap(digits[pos1], digits[pos2]);
  __int64 result = 0;
  for(int i = 0; i < 9; i++)
  {
    result += (__int64)digits[i] * powersOf10[i];
  }
  return result;
}

/*void generate(__int64 config)
{
  if(lists.count(config) != 0)
    return;
  int pos = get9Pos(config);
  lists.insert(make_pair(config, deque<__int64>()));
  for(int i = 0; i < 4; i++)
  {
    if(directions[pos][i] == -1)
      return;
    __int64 next = SwapDigits(config, pos, directions[pos][i]);
    lists[config].push_back(next);//Попробовать получить итератор на lists[config], если будет тормозить
    generate(next);
  }
}*/

int charToCode(char value)
{

  switch(value)
  {
  case 'Х': return 1;
  case 'А': return 2;
  case 'М': return 3;
  case 'Е': return 4;
  case 'Л': return 5;
  case 'О': return 7;
  case 'Н': return 8;
  default: return 9;
  }
  return 9;
}

void bfs(__int64 startVertex)
{
  bfsResult.clear();
  bfsResult.insert(make_pair(startVertex, make_pair(startVertex, 0)));
  //count1++;
  queue<__int64> Q;
  Q.push(startVertex);

  map<__int64, pair<__int64, int>>:: iterator currentVertexBfsIt;
  while(!Q.empty())
  {
    __int64 currentVertex = Q.front();
    Q.pop();
    int pos = get9Pos(currentVertex);
    currentVertexBfsIt = bfsResult.find(currentVertex);
    //count1++;
    for(int i = 0; i < 4; i++)
    {
      if(directions[pos][i] == -1)
        break;
      __int64 next = SwapDigits(currentVertex, pos, directions[pos][i]);
      if(bfsResult.find(next) == bfsResult.end())//Ещё не пройдена
      {
        //count1++;
        bfsResult.insert(make_pair(next, make_pair(currentVertex, currentVertexBfsIt->second.second + 1)));
        //count1++;
        if(next == 123454789)//Дальше нет смысла
          return;
        Q.push(next);
      }
    }
  }
}

void printAnwser(__int64 vertex)
{
  //count1++;
  if(bfsResult[vertex].first != vertex)
  {
    //count1++;
    printAnwser(bfsResult[vertex].first);
    int pos = get9Pos(vertex);
    printf("%d %d\n", (pos / 3) + 1, (pos % 3) + 1);
  }
}

int main()
{
  double time = clock();
  int QWE;
  freopen("input.txt", "r", stdin);
#ifdef LOCALTEST
  scanf("%d\n", &QWE);
  freopen("output.txt", "w", stdout);
#else
  QWE = 1;
#endif
  //Генерируем дерево
  for(int T = 0; T < QWE; T++)
  {
    //count1 = 0;
    __int64 powOf10 = 100000000;
    __int64 configuration = 0;//Конфигурация поля
    for(int i = 0; i < 3; i++)
    {
      char first, second, third;
      cin.get(first);
      cin.get(second);
      cin.get(third);
      cin.get();
      //лень цикл писать
      configuration += (__int64)charToCode(first) * powOf10;
      powOf10 /= 10;
      configuration += (__int64)charToCode(second) * powOf10;
      powOf10 /= 10;
      configuration += (__int64)charToCode(third) * powOf10;
      powOf10 /= 10;
    }
    bfs(configuration);
    printf("%d\n", bfsResult[123454789].second);
    //count1++;
    if(bfsResult[123454789].second != 0)
    {
      printAnwser(123454789);
    }
    //printf("%d\n", count1);
  }
  time = clock() - time;
  printf("%lf\n", (time)/CLOCKS_PER_SEC);
  return 0;
}