#include <stdio.h>

using namespace std;

__int64 max(__int64 a, __int64 b)
{
  return a > b ? a : b;
}

int main()
{
  int n;
  scanf("%d", &n);
  __int64* data = new __int64[n];
  __int64* a = new __int64[n];
  __int64* b = new __int64[n];
  b[n - 1] = 0;
  scanf("%I64d", &data[0]);
  a[0] = data[0];
  for(int i = 1; i < n; i++)
  {
    scanf("%I64d", &data[i]);
    /*if(i != 1)
    {*/
      a[i] = a[i - 1] ^ data[i];
    /*}
    else
    {
      a[i] = data[0] ^ data[i];
    }*/
  }
  b[n - 1] = data[n - 1];
  for(int i = n - 2; i >= 0; i--)
  {
    /*if(i != n - 2)
    {*/
      b[i] = b[i + 1] ^ data[i];
    /*}
    else
    {*/
      //b[i] = data[n - 1] ^ data[n - 2];
    //}
  }
  __int64 result = max(0LL, max(data[0], data[n - 1]));
  result = max(result, max(a[n - 1], b[0]));
  for(int i = 0; i < n - 1; i++)
  {
    result = max(result, a[i] ^ b[i + 1]);
    result = max(result, a[i]);
    result = max(result, b[i + 1]);
  }
  printf("%I64d", result);
  return 0;
}
