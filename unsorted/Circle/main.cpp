#include <iostream>
//#include <map>
#include "stdio.h"

using namespace std;

//map<int, int> MathCache;

/*int CalcUnic(int value)
{
  if(!MathCache.count(value))
    {
      int result = 2 * CalcUnic(value - 2)-1;
      for(int i = 2; i <= value-2; i=i+2)
        {
          result += CalcUnic(i)+CalcUnic(value -i)-1;
        }
      MathCache.insert(make_pair(value, result));
    }
  return MathCache[value];
}*/

int main()
{
  int k;
  scanf("%d", &k);
  __int64 *table=new __int64[k+1];
  table[0]=1;
  for (int m=1; m<=k; ++m)
  {
    table[m]=0;
    for (int j=0; j<m; ++j)
      table[m]+=table[j]*table[m-1-j];
  }
  /*MathCache.insert(make_pair(2, 1));
  MathCache.insert(make_pair(4, 2));*/
  printf("%I64d %d", table[k], k + 1);
  return 0;
}
