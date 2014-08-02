#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  deque<pair<int, int>> d;
  for(int i = 0; i < n; i ++)
  {
    int a;
    scanf("%d", &a);
    d.push_back(make_pair(a, i + 1));
  }
  while(d.size() != 1)
  {
    pair<int, int> p = d.front();
    d.pop_front();
    if(p.first > m)
    {
      p.first -= m;
      d.push_back(p);
    }
  }
  printf("%d\n", d.front().second);
  return 0;
}