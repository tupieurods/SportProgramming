#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

#pragma warning(disable: 4996)

using namespace std;

#define MOD 1000000007

int n, m, k;
bool inputFail;
vector<pair<int, int>> edges;
int powersOf2[1000009];

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  inputFail = false;
  edges.clear();
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    if(((to - from) != 1) && ((to - from) != (k + 1)))
    {
      inputFail = true;
      break;
    }
    if((to - from) == (k + 1))
    {
      edges.push_back(make_pair(from, to));
    }
  }
}

int answer;

void Solve()
{
  answer = 0;
  if(inputFail)
  {
    //printf("fail\n");
    return;
  }
  m = edges.size();
  if(k >= n - 1)
  {
    answer = 1;
    return;
  }
  for(int i = 1; i < m; i++)
  {
    //Если не все рёбра начинаются внутри дуги первого
    //Значит можно нарушить условие 5
    if(!(edges[i].first > edges[0].first && edges[i].first < edges[0].second))
    {
      return;
    }
  }
  //Если нет рёбер второго типа. Либо оставляем как есть
  //Либо добиваем до прямой линии
  if(m == 0)
  {
    answer++;
  }
  for(int i = 0; i < n; i++)
  {
    int from = i + 1;
    int to = from + k + 1;
    //Чтобы нельзя было внутри дуги(и после неё) сократить путь
    if(to > n || (m > 0 && edges[0].first < from))
    {
      break;
    }
    //Чтобы нельзя было сократить путь внутри дуги
    if(m > 0 && !(from <= edges[0].first && to > edges[m - 1].first))
    {
      continue;
    }
    //Считаем что мы сами провели первое ребро
    //Иначе не все комбинации с ним будут учтены
    if(m > 0 && from == edges[0].first)
    {
      from--;
    }
    //[from; to)
    to = min(to, n - k);
    //Количество вершин между [from; to)
    //Вычесть количество вершин с выходящими рёбрами
    //-1 для приведения [from; to) к виду [from; to]
    int powerVal = to - from - m - 1;
    answer = (answer + powersOf2[powerVal]) % MOD;
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  powersOf2[0] = 1;
  powersOf2[1] = 2;
  for(int i = 2; i < 1000009; i++)
  {
    powersOf2[i] = (powersOf2[i - 1] + powersOf2[i - 1]) % MOD;
  }
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