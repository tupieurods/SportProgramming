#include <stdio.h>
#include <vector>

using namespace std;

vector< pair<int, int> > copies;

vector<int> data;

void copy()
{
  if(copies.size() == 0)
  {
    copies.push_back(new int[1]);
    copies[0] = data.size();
  }
  else
  {

  }
}

int getTop()
{
  int result = 0;
  return result;
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(tmp > 0)
    {
      data.push_back(tmp);
    }
    else if(tmp == -1)
    {
      printf("%d\n", getTop());
    }
    else
    {
      copy();
    }
  }
  return 0;
}
