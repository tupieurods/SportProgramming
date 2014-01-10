#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int> > v;
  for(int i = 0; i < n; i++)
  {
    int c, t;
    scanf("%d %d", &c, &t);
    v.push_back(make_pair(c, t));
  }
  int currTime = v[0].first * v[0].second;
  int current = 1;
  for(int i = 0; i < m; i++)
  {
    int vtime;
    scanf("%d", &vtime);
    while(vtime > currTime)
    {
      currTime += v[current].first * v[current].second;
      current++;
    }
    printf("%d\n", current);
  }
  return 0;
}
