#include <stdio.h>
#include <set>
#include <vector>

using namespace std;
//День наркоманских решений
set<int> sets[48];
int p[48];

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    p[i] = i;
    sets[i].insert(i);
  }
  for(int i = 0; i < m; i++)
  {
    int f, s;
    scanf("%d %d", &f, &s);
    f--;
    s--;
    if(p[f] != p[s])
    {
      sets[p[f]].insert(sets[p[s]].begin(), sets[p[s]].end());
      sets[p[s]].clear();
      p[s] = p[f];
    }
  }
  vector<int> x3, x2, x1;
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    int sz = sets[i].size();
    if(sz == 3)
      x3.push_back(i);
    else if(sz == 2)
      x2.push_back(i);
    else if(sz == 1)
      x1.push_back(i);
    else if(sz != 0)
      cnt++;
  }
  if(cnt != 0 || (x2.size() > x1. size()) || ((x1.size() - x2.size()) % 3 != 0))
  {
    printf("-1");
    return 0;
  }
  set<int>::iterator itS;
  vector<int>::iterator itV;
  for(itV = x3.begin(); itV != x3.end(); itV++)
  {
    for(itS = sets[*itV].begin(); itS != sets[*itV].end(); itS++)
    {
      printf("%d ", (*itS) + 1);
    }
    printf("\n");
  }
  int pos = 0;
  for(itV = x2.begin(); itV != x2.end(); itV++)
  {
    for(itS = sets[*itV].begin(); itS != sets[*itV].end(); itS++)
    {
      printf("%d ", (*itS) + 1);
    }
    printf("%d\n", x1[pos] + 1);
    pos++;
  }
  for(int i = 0; i + pos < x1.size(); i++)
  {
    printf("%d ", x1[pos + i] + 1);
    if((i + 1) % 3 == 0)
      printf("\n");
  }
  return 0;
}
