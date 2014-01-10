#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d", &n);
    int minimal = 2000, maximal = -2000;
    map<int, int> m;
    map<int, int>::iterator it;
    for(int i = 0; i < n; i++)
    {
      int val;
      scanf("%d", &val);
      minimal = min(minimal, val);
      maximal = max(maximal, val);
      it = m.find(val);
      if(it != m.end())
      {
        it->second++;
      }
      else
      {
        m.insert(make_pair(val, 1));
      }
    }
    it = m.find(minimal);
    if(it->second == 1)
    {
      m.erase(it);
    }
    else
    {
      it->second--;
    }
    it = m.find(maximal);
    if(it->second == 1)
    {
      m.erase(it);
    }
    else
    {
      it->second--;
    }
    printf("%d ", maximal);
    for(it = m.begin(); it != m.end(); it++)
    {
      for(int i = 0; i < it->second; i++)
      {
        printf("%d ", it->first);
      }
    }
    printf("%d ", minimal);
    printf("\n");
  }
  return 0;
}