#include <stdio.h>
#include <map>

using namespace std;

struct cube
{
  int a;
  int count;
};

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  map<int, int> data;
  map<int, int>::iterator it;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    it = data.find(tmp);
    if(it != data.end())
    {
      it->second++;
    }
    else
    {
      data.insert(make_pair(tmp, 1));
    }
  }
  int minus = 0;
  for(it = data.begin(); it!= data.end(); it++)
  {
    if(n - minus == k)
    {
      printf("%d %d", it->first, it->first);
      return 0;
    }
    else
    {
      minus += it->second;
    }
  }
  printf("-1\n");
  return 0;
}
