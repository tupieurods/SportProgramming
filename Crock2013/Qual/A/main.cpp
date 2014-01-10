#include <stdio.h>
#include <map>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  map<int, int> ids;
  map<int, int>::iterator it;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    it = ids.find(tmp);
    if(it == ids.end())
    {
      ids.insert(make_pair(tmp, 1));
    }
    else
    {
      it->second++;
    }
  }
  int answer = 0;
  for(it = ids.begin(); it != ids.end(); it++)
  {
    if(it->first == 0 || it->second == 1)
     continue;
    if(it->second == 2)
    {
      answer++;
      continue;
    }
    answer = -1;
    break;
  }
  printf("%d", answer);
  return 0;
}
