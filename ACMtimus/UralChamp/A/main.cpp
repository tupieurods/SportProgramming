#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return strcmp(a, b) < 0;
   }
};

int n, m;
map<char*, pair<int, bool>, cmp_str> options;
map<int, int> pairs;
map<int, int>::iterator ItPairs;
__int64 w, h;
__int64 p;
__int64 current;

void ReadData()
{
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    int k;
    char *str = new char[15];
    scanf("%s", str);
    scanf("%d%*c", &k);
    options.insert(make_pair(str, make_pair(k, true)));
    ItPairs = pairs.find(k);
    if(ItPairs != pairs.end())
      ItPairs->second++;
    else
      pairs.insert(make_pair(k, 1));
  }
  scanf("%d %d %d%*c", &w, &h, &p);
}

int cnt;

void WriteData()
{
  if(cnt > 35)
  {
    printf("Slideshow\n");
    return;
  }
  __int64 cur = current;
  for(ItPairs = pairs.begin(); ItPairs != pairs.end(); ItPairs++)
  {
    cur *= ItPairs->first;
    if(cur > p)
      break;
  }
  if(p / cur < 10LL)
  {
    printf("Slideshow\n");
  }
  else if(p / cur >= 60LL)
  {
    printf("Perfect\n");
  }
  else
  {
    printf("So-so\n");
  }
}

void Solve()
{
  cnt = n;
  current = w * h;
  WriteData();
  scanf("%d%*c", &m);
  char *first = new char[15], *second = new char[15];
  map<char*, pair<int, bool>, cmp_str>::iterator it;
  for(int i = 0; i < m; i++)
  {
    scanf("%s", first);
    if(first[1] == 'f' || first[1] == 'n')
    {
      scanf("%s%*c", second);
      it = options.find(second);
      if(it == options.end())
        throw;
      it->second.second = !it->second.second;
      if(it->second.second)
      {
        cnt++;
        ItPairs = pairs.find(it->second.first);
        if(ItPairs != pairs.end())
          ItPairs->second++;
        else
          pairs.insert(make_pair(it->second.first, 1));
      }
      else
      {
        ItPairs = pairs.find(it->second.first);
        if(ItPairs->second == 1)
          pairs.erase(ItPairs);
        else
          ItPairs->second--;
        cnt--;
      }
    }
    else//Resolution
    {
      scanf("%d %d%*c", &w, &h);
      current = w * h;
    }
    WriteData();
  }
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
    //WriteData();
  }
  return 0;
}