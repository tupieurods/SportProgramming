//Моё изначальное решение
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

list<pair<int, int>> l;
set<int> m;
int n;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int f, s;
    scanf("%d %d", &f, &s);
    l.push_back(make_pair(f, s));
    m.insert(s);
  }
  l.sort();
}

int answer;

void Solve()
{
  answer = 0;
  while(l.size() != 0)
  {
    list<pair<int, int>>::iterator it1, it2, copy;
    it1 = l.begin();
    it2 = l.begin();
    it2++;
    m.erase(it1->second);
    while(it2 != l.end())
    {
      if(it2->first > it1->second || (*m.begin() > it1->second))
      {
        break;
      }
      if((it2->first > it1->first) && (it2->second < it1->second))
      {
        copy = it2;
        m.erase(it2->second);
        it2++;
        l.erase(copy);
        answer++;
      }
      else
      {
        it2++;
      }
    }
    l.pop_front();
  }
}

void WriteData()
{
  printf("%d\n", answer);
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

//Решение после прочтения разбора
/*#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <algorithm>

using namespace std;

list<pair<int, int>> l;
int n;

void ReadData()
{
  scanf("%d", &n);
  l.clear();
  for(int i = 0; i < n; i++)
  {
    int f, s;
    scanf("%d %d", &f, &s);
    l.push_back(make_pair(f, s));
  }
  l.sort();
}

int answer;

void Solve()
{
  answer = 0;
  int m = l.begin()->second;
  for(list<pair<int, int>>::iterator it = l.begin(); it != l.end(); it++)
  {
    if(m > it->second)
    {
      answer++;
    }
    m = max(m, it->second);
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
}  */
