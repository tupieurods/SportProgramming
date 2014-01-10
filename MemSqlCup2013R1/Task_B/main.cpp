#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;
__int64 n;
__int64 current;

double calc(__int64 value)
{
  double result = 0;
  if(value % 2LL == 0)
  {
    result = (value / 2.0) * (value - 1.0) + 1.0 * value * current;
  }
  else
  {
    result = ((value - 1.0) / 2.0) * value + 1.0 * value * current;
  }
  return result;
}


bool Validate(__int64 value)
{
  if(value == 0)
    return false;
  __int64 checker = 0;
  while(value % 2 == 0)
  {
    checker += value / 2;
    value /= 2;
  }
  checker += ((value - 1LL) / 2LL) * value;
  return checker == n;
}

int main()
{
  scanf("%I64d", &n);
  set<__int64> answer;
  for(int i = 0; i < 63; i++)
  {
    /*if(i == 52)
      printf("shit\n");*/
    current = (1LL << i) - 1LL;
    __int64 l = 1LL;
    __int64 r = 10000000000LL;
    while(r - l > 5LL)
    {
      __int64 center = l + (r - l) / 2LL;
      double val = calc(center);
      if(val > n)
      {
        r = center;
      }
      else
      {
        l = center;
      }
    }
    /*if(i == 1)
      printf("shit\n");*/
    for(__int64 j = l; j <= r; j++)
    {
      /*if(j == 707106779)
        printf("wtf\n");
      if(i == 52 && j == 4095)
        printf("\t%d\n", j);*/
      if(Validate((1LL << i) * j))
      {
        answer.insert((1LL << i) * j);
      }
    }
  }
  /*if(Validate(1414213558))
    answer.insert(1414213558);*/
  if(answer.size() == 0)
  {
    printf("-1\n");
    return 0;
  }
  for(set<__int64>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%I64d\n", *it);
  }
  return 0;
}