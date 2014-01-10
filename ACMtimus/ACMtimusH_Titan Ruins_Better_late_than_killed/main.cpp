#include <stdio.h>
#include <map>
#include <set>

using namespace std;

int main()
{
  int n, max;
  scanf("%d %d", &n, &max);
  map<int, int> data;
  set<int> minimal;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(data.count(tmp) == 0)
    {
      data.insert(make_pair(tmp, 1));
      minimal.insert(tmp);
    }
    else
      data[tmp]++;
  }
  int moneyCount = 0;
  int castCount = 0;
  set<int>::iterator i = minimal.begin();
  while(true)
  {
    int removed = 0;
    for(; i != minimal.end(); i++)
    {
      if((removed+data[*i])*(*i) <= max)
      {
        removed += data[*i];
        data.erase(*i);
      }
      else
        break;
    }
    if(removed == 0)
      break;
    moneyCount += removed;
    castCount++;
    if(i==minimal.end())
      break;
  }
  printf("%d %d", moneyCount, castCount);
  return 0;
}
