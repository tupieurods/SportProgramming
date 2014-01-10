//#define LOCALTEST

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d\n", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d\n", &n);
    set<int, greater<int>>* columns = new set<int, greater<int>>[n + 1];
    for(int i = 1; i < n; i++)
    {
      int x, y;
      scanf("%d %d", &x, &y);
      columns[y].insert(x);
    }
    deque<pair<int, pair<int, int> > > anwser;
    for(int i = 1; i < n; i++)
    {
      int indexMax = i;
      for(int j = i + 1; j <= n; j++)
      {
        if(columns[indexMax].size() < columns[j].size())
          indexMax = j;
      }
      if(i != indexMax)
      {
        swap(columns[i], columns[indexMax]);
        anwser.push_back(make_pair(2, make_pair(i, indexMax)));
      }
    }
    int* rows = new int[n + 1];
    //memset(rows, 0xFF, sizeof(int) * (n + 1));
    for(int i = 1; i <= n; i++)
    {
      int current = -1;
      for(int j = 1; j <= n; j++)
      {
        if(columns[j].find(i) != columns[j].end())
          current = j;
      }
      rows[i] = current;
    }
    for(int i = 1; i < n; i++)
    {
      int indexMin = i;
      for(int j = i + 1; j <= n; j++)
      {
        if(rows[indexMin] > rows[j])
          indexMin = j;
      }
      if(i != indexMin)
      {
        swap(rows[i], rows[indexMin]);
        anwser.push_back(make_pair(1, make_pair(i, indexMin)));
      }
    }
    //Вывод ответа
    printf("%d\n", anwser.size());
    if(anwser.size() != 0)
    {
      for(deque<pair<int, pair<int, int> > >::iterator it = anwser.begin(); it != anwser.end(); it++)
      {
        printf("%d %d %d\n", it->first, it->second.first, it->second.second);
      }
    }
  }
  return 0;
}