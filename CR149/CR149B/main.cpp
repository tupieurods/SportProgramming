#include <stdio.h>
#include <math.h>

using namespace std;

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int n;
  scanf("%d", &n);
  int start = 0x7FFFFFFF;
  int finish = 0;
  int index = 0;
  int maximal = 0;

  for(int i = 1; i <= n; i++)
  {
    int tmpStart, tmpFinish;
    scanf("%d %d", &tmpStart, &tmpFinish);
    maximal = max(tmpFinish, maximal);
    if(tmpStart <= start)
    {
      if(tmpStart == start)
      {
        if(tmpFinish > finish)
        {
          index = i;
          finish = tmpFinish;
        }
      }
      else
      {
        index = i;
        start = tmpStart;
        finish = tmpFinish;
      }
    }
  }
  //printf("%d %d %d\n",maximal,finish,index);
  if(maximal > finish)
    printf("-1");
  else
    printf("%d\n", index);
  return 0;
}
