#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#pragma warning(disable: 4996)

int n, m;
int p[3009];

void ReadData()
{
  memset(p, 0, sizeof(p));
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &p[i]);
    p[i]--;
  }
  scanf("%d", &m);
}


bool mark[3009];

void markCycle(int idx)
{
  for(int i = idx; !mark[i]; i = p[i])
  {
    mark[i] = true;
  }
}

vector<pair<int, int>> answer;

void Solve()
{
  memset(mark, 0, sizeof(mark));
  answer.clear();
  int targetCyclesN = n - m;
  int c = 0;
  for(int i = 0; i < n; i++)
  {
    if(!mark[i])
    {
      markCycle(i);
      c++;
    }
  }
  int delta = abs(targetCyclesN - c);
  if(c > targetCyclesN)//надо убрать некоторые циклы
  {
    memset(mark, 0, sizeof(mark));
    markCycle(0);
    for(int i = 1; delta != 0; i++)
    {
      if(!mark[i])
      {
        markCycle(i);
        delta--;
        answer.push_back(make_pair(0, i));
      }
    }
  }

  if(c < targetCyclesN)//надо добавить циклов
  {
    int idxInCycle[3009];
    for(int i = 0; delta != 0; i++)
    {
      memset(idxInCycle, 0xFF, sizeof(int)* n);
      int idx = 0;
      for(int j = p[i]; i != j; j = p[j])
      {
        idxInCycle[j] = idx;
        idx++;
      }
      idxInCycle[i] = idx;//Устанавливая в i наибольший индекс мы гарантируем
      //что при удалении у нас i останется в нужном нам цикле
      idx = 0;
      for(int j = i + 1; j < n && delta != 0; j++)
      {
        if(idxInCycle[j] >= idx)
        {
          answer.push_back(make_pair(i, j));
          idx = idxInCycle[j] + 1;
          delta--;
          swap(p[i], p[j]);//Сделали обмен, отразим новое разбитие на циклы в массиве
        }
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); ++it)
  {
    printf("%d %d ", it->first + 1, it->second + 1);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}