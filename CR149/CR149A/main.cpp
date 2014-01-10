#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int x, y, a, b;
  scanf("%d %d %d %d", &x, &y, &a, &b);
  vector< pair<int, int> > list;
  for(int i=a; i<=x;i++)
  {
    for(int j=b; j<=y; j++)
    {
      if(i>j)
        list.push_back(make_pair(i,j));
    }
  }
  printf("%d\n",list.size());
  for(unsigned int i = 0; i < list.size(); i++)
  {
    printf("%d %d\n", list[i].first, list[i].second);
  }
  return 0;
}
