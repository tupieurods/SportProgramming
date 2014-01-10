#include <stdio.h>
#include <string.h>

using namespace std;

__int64* data;

__int64 primitive(__int64 value)
{
  __int64 result = 0;
  while(value != 0L)
  {
    if((value % 10L) == 2L)
      result++;
    value /= 10L;
  }
  return result;
}

__int64 binPow(__int64 value, int power)
{
  if(power == 0)
    return 1;
  if((power % 2) == 0)
  {
    __int64 tmp = binPow(value, power / 2);
    return tmp * tmp;
  }
  else
  {
    return value * binPow(value, power - 1);
  }
}

__int64 f1(__int64 value)
{
  if(data[value] != -1)
    return data[value];
  data[value] = 10 * f1(value - 1) + binPow(10, value - 1);
  return data[value];
}

__int64 f2(__int64 value)
{
  if(value == 0)
    return 0;
  __int64 copy = value;
  int t = 0;
  int i = 0;
  while(copy != 0)
  {
    t = copy % 10;
    copy /= 10;
    i++;
  }
  __int64 result = f2(value - t * binPow(10, i - 1));
  if(t > 0)
  {
    if(t == 1)
    {
      result += f1(i - 1);
    }
    else if(t == 2)
    {
      result += 2 * f1(i - 1) + value - t * binPow(10, i - 1) + 1;
    }
    else
    {
      result += t * f1(i - 1) + binPow(10, i - 1);
    }
  }
  //printf("%d %d\n", t, i);
  return result;
}

int main()
{
  /*data = new __int64[30];
  memset(data, 0xFF, sizeof(__int64) * 30);
  data[0] = 0;
  data[1] = 1;*/
  __int64 n;
  scanf("%I64d", &n);
  data = new __int64[30];
  memset(data, 0xFF, sizeof(__int64) * 30);
  data[0] = 0;
  data[1] = 1;
  /*__int64 count = 0;
  for(__int64 i = 0; i <= n; i++)
  {
    count += primitive(i);
  }
  printf("%I64d\n", count);*/
  printf("%I64d\n", f2(n));
  return 0;
}
