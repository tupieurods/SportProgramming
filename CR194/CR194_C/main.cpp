#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<__int64> vals;

__int64 f(__int64 val)
{
  __int64 result = 0;
  for(int i = 1; i < vals.size(); i++)
  {
    if(val % vals[i] != 0)
    {
      result = val / vals[i];
      __int64 tmp = vals[i] * result;
      while(tmp < val)
      {
        tmp += vals[i];
        result++;
      }
      break;
    }
  }
  if(result == 0)
    result = 1;
  return result;
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  __int64 val = 1;
  while(val < 100000000000000000LL)
  {
    vals.push_back(val);
    val *= 3;
  }
  for(int T = 0; T < QWE; T++)
  {
    __int64 n;
    scanf("%I64d", &n);
    printf("%I64d\n", f(n));
  }
  return 0;
}