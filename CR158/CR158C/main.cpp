#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>

using namespace std;

int main()
{
  __int64 n, x;
  cin >> n >> x;
  __int64* data = new __int64[n];
  //memset(data, 0, sizeof(__int64) * n);
  x--;
  __int64 minimal = _I64_MAX;
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d ", &data[i]);
    //cin >> data[i];
    if(data[i] < minimal)
    {
      minimal = data[i];
    }
  }
  __int64 balls = 0;
  __int64 current = x;
  while(data[current] != minimal)
  {
    data[current]--;
    balls++;
    if(current == 0)
    {
      current = n - 1;
    }
    else
    {
      current--;
    }
  }
  data[current] = balls + current * minimal + (n - current) * (minimal);
  for(int i = 0; i < n; i++)
  {
    printf("%I64d ", i != current ? data[i] - minimal : data[i]);;
  }
  return 0;
}
