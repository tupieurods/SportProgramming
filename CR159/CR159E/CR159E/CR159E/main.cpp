#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <climits>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

//#define LOCALTEST

int k;

struct unit
{
  int id;
  int time, from, to;
};

int compare(const void* a, const void* b)
{
  unit realA = *(unit*)a;
  unit realB = *(unit*)b;
  return (realA.time - realB.time);
}

inline int F(int value)
{
 return value - (value & (value - 1));
}

void modify(int* arr, int pos, int value)
{
  int i = pos;
  while(i <= (1 << k))
  {
    arr[i] += value;
    i += F(i);
  }
}

int count(int* arr, int pos)
{
  int result = 0;
  int i = pos;
  while(i > 0)
  {
    result += arr[i];
    i -= F(i);
  }
  return result;
}

int getCountN(int* arr, int pos)
{
  if(pos == 1)
    return count(arr, pos);
  return count(arr, pos) - count(arr, pos - 1);
}

int getCountLR(int* arr, int l, int r)
{
  if(l == r)
    return getCountN(arr, l);
  return count(arr, r) - count(arr, l - 1);
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
  for(int T = 0; T < QWE; T++)
  {
    int n, m;
    scanf("%d %d", &n, &m);
    k = 0;
    //Посчитать k для дерева Фенвика
    while((1<<k) < m)
      k++;
    unit* data = new unit[n];
    for(int i = 0; i < n; i++)
    {
      data[i].id = i;
      scanf("%d %d %d", &data[i].time, &data[i].from, &data[i].to);
      data[i].from--;
      data[i].to--;
    }
    qsort(data, n, sizeof(unit), compare);

    //Число чуваков которые хотят на этаж i
    int* target = new int[(1 << k) + 1];
    memset(target, 0, ((1 << k) + 1) * sizeof(int));

    //Список чуваков которые стоят на этаже i
    deque<int>* from = new deque<int>[m];
    int* fromCount = new int[(1 << k) + 1];
    memset(fromCount, 0, ((1 << k) + 1) * sizeof(int));

    //Индексы чуваков в лифте
    deque<int>* lift = new deque<int>[m];

    //Время выхода чуваков из лифта
    __int64* anwser = new __int64[n];
    int anwsered = 0;

    //Время
    __int64 time = 0;

    //Этаж
    int floor = 0;

    //Последний НЕ обработаный чувак
    int last = 0;

    set<int> backToTheFuture;
    set<int>::iterator itEND = backToTheFuture.end();
    while(anwsered != n)
    {
      //Посчитать pUp
      int pUp = getCountLR(target, floor + 2, m) + getCountLR(fromCount, floor + 2, m);
      //Посчитать pDown
      int pDown = count(target, floor) + count(fromCount, floor);
      //Передвинуть лифт
      __int64 timeDelta = 0;
      set<int>::iterator itSet;
      if(pUp >= pDown)
      {
        if(pUp != 0)
        {
          //Показывает через сколько кто-то подойдёт на какой-либо этаж
          __int64 delta = last == n ? _I64_MAX : (__int64)data[last].time - time;
          //Показывает минимальное время до входа
          __int64 minimalComeIn = _I64_MAX;
          if(backToTheFuture.size() != 0)
          {
            itSet = backToTheFuture.lower_bound(floor);
            if(itSet != backToTheFuture.end())
              minimalComeIn = *itSet - floor;
          }
          //минимальное время до выхода
          __int64 minimalComeOut = _I64_MAX;
          if(backToTheFuture.size() != 0)
          {
            itSet = backToTheFuture.lower_bound(floor);
            if(itSet != backToTheFuture.end())
              minimalComeOut = *itSet - floor;
          }
          timeDelta = min(delta, min(minimalComeIn, minimalComeOut));
        }
        else
        {
          time = data[last].time;
        }
      }
      else
      {
        __int64 delta = last == n ? _I64_MAX : (__int64)data[last].time - time;
        //Показывает минимальное время до входа
        __int64 minimalComeIn = _I64_MAX;
        if(backToTheFuture.size() != 0)
        {
          itSet = backToTheFuture.lower_bound(floor);
          if(itSet != backToTheFuture.end())
          {
            minimalComeIn = floor - *(--itSet);
          }
          else
          {
            itSet = itEND;
            minimalComeIn = floor - *(--itSet);
          }
        }
        //минимальное время до выхода
        __int64 minimalComeOut = _I64_MAX;
        if(backToTheFuture.size() != 0)
        {
          itSet = backToTheFuture.lower_bound(floor);
          if(itSet != backToTheFuture.end())
          {
            minimalComeOut = floor - *(--itSet);
          }
          else
          {
            itSet = itEND;
            minimalComeOut = floor - *(--itSet);
          }
        }
        timeDelta = -min(delta, min(minimalComeIn, minimalComeOut));
      }
      floor += (int)timeDelta;
      //Изменить время
      time += abs(timeDelta);
      //Обработка перехода: Не подошёл к лифту -> Подошёл и ждёт на своём этаже
      while(last != n)
      {
        if(data[last].time != time)
          break;
        from[data[last].from].push_back(last);
        modify(fromCount, data[last].from + 1, 1);
        backToTheFuture.insert(data[last].from);
        last++;
      }
      //Обработка перехода: Подошёл и ждёт на своём этаже -> В лифте
      if(from[floor].size() != 0)
      {
        for(unsigned int i = 0; i < from[floor].size(); i++)
        {
          lift[data[from[floor][i]].to].push_back(from[floor][i]);
          modify(target, data[from[floor][i]].to + 1, 1);
          backToTheFuture.insert(data[from[floor][i]].to);
        }
        from[floor].clear();
        modify(fromCount, floor + 1, -getCountN(fromCount, floor + 1));
      }
      //Обработка перехода: В лифте -> Вышел на нужном этаже
      if(lift[floor].size() != 0)
      {
        for(deque<int>::iterator it = lift[floor].begin(); it != lift[floor].end(); it++)
        {
          anwser[data[*it].id] = time;
        }
        anwsered += lift[floor].size();
        modify(target, floor + 1, -getCountN(target, floor + 1));
        lift[floor].clear();
      }
      backToTheFuture.erase(floor);
    }
    for(int i = 0; i < n; i++)
    {
      printf("%I64d\n", anwser[i]);
    }
    printf("\n");
  }
  return 0;
}
/*#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
  freopen("out.txt", "w", stdout);
  int n = 100000;
  int m = 100000;
  printf("%d %d\n", n, m);
  srand(time(NULL));
  for(int i = 0; i < n; i++)
  {
    int rTime = 1 + rand() % m;
    int rFrom = 1 + rand() % m;
    int rTo = 1 + rand() % m;
    printf("%d %d %d\n", rTime, rFrom, rTo);
  }
  return 0;
} */