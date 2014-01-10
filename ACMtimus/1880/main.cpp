#include <stdio.h>
#include <map>

using namespace std;

int main()
{
  map<int, int> m;
  map<int, int>::iterator it;
  for(int i = 0; i < 3; i++)
  {
    int n;
    scanf("%d", &n);
    for(int j = 0; j < n; j++)
    {
      int val;
      scanf("%d", &val);
      it = m.find(val);
      if(it == m.end())
        m.insert(make_pair(val, 1));
      else
        it->second++;
    }
  }
  int answer = 0;
  for(it = m.begin(); it != m.end(); it++)
  {
    if(it->second == 3)
      answer++;
  }
  printf("%d\n", answer);
  return 0;
}