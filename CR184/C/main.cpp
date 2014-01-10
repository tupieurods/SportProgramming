#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  set<int> m;
  set<int>::iterator it;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    while((it = m.find(val)) != m.end())
    {
      m.erase(it);
      val++;
    }
    m.insert(val);
  }
  int maximal = 0;
  for(it = m.begin(); it != m.end(); it++)
  {
    maximal = max(*it, maximal);
  }
  /*if(maximal == m.size())
    printf("0\n");
  else*/
  printf("%d\n", maximal - m.size() + 1);
  return 0;
}
