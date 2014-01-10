#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

__int64 l, r;
__int64 powerOf10[20];

void ReadData()
{
  scanf("%I64d %I64d", &l, &r);
}

__int64 answer;

__int64 f(__int64 val)
{
  if(val < 10)
    return val;
  std::deque<int> numbers;
  __int64 copy = val;
  while(copy != 0)
  {
    numbers.push_front(copy % 10);
    copy /= 10;
  }
  __int64 result = 9LL;
  int len = numbers.size();
  for(int d = 1; d < 10; d++)
  {
    for(int i = 0; i < len; i++)
    {
      if(i < len - 2
        || (i == len - 2 && d < numbers[0]))
      {
        result += powerOf10[i];
      }
      if(i == len - 2 && d == numbers[0])
      {
        result += (val % powerOf10[len - 1])/ 10LL;
      }
    }
  }
  if(numbers[0] <= numbers[len - 1])
    result++;
  return result;
}

void Solve()
{
  answer = f(r) - f(l - 1);
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  powerOf10[0] = 1;
  for(int i = 1; i < 19; i++)
  {
    powerOf10[i] = powerOf10[i - 1] * 10LL;
  }
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}