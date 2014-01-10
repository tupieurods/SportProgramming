#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
  int* data = new int[1000001];
  //memset(data, 1, 1000001);
  for(int i = 0; i < 1000001; i++)
  {
    data[i] = 1;
  }
  data[1]=0;
  for(int i = 2; i*i <= 1000000; i++)
  {
    if(data[i] == 1)
      for(int j = i * i; j <= 1000000; j += i)
        data[j] = 0;
  }
  __int64 n;
  scanf("%I64d", &n);
  for(__int64 i = 0; i < n; i++)
  {
    __int64 inData;
    scanf("%I64d", &inData);
    __int64 tmp = (__int64)sqrt(inData);
    if((data[tmp] == 1) && (tmp*tmp == inData))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
