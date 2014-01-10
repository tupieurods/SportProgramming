#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

__int64 a;
int len, halfLen, top;
bool haveCenter;

bool ReadData()
{
  char str[19];
  scanf("%s%*c", str);
  len = strlen(str);
  if(len == 1)
  {
    return false;
  }
  a = 0LL;
  haveCenter = len % 2 == 1;
  halfLen = len / 2;
  for(int i = 0; i < len; i++)
  {
    a = a * 10LL + (__int64)(str[i] - '0');
  }
  top = 1;
  for(int i = 0; i < halfLen; i++)
  {
    top *= 10;
  }
  return true;
}

__int64 answer;

void Solve()
{
  answer = 10000000000LL;
  __int64 b = 0LL;
  for(int i = 0; i < top; i++)
  {
    __int64 reversed = 0;
    __int64 copy = b;
    for(int j = 0; j < halfLen; j++)
    {
      reversed = reversed * 10LL + copy % 10;
      copy /= 10;
    }
    if(haveCenter)
    {
      for(int j = 0; j < 10; j++)
      {
        __int64 currentVal = (reversed * 10 + j) * top + b;
        if(currentVal - a >= 0)
        {
          answer = std::min(answer, currentVal - a);
        }
      }
    }
    else
    {
      __int64 currentVal = reversed * top + b;
      if(currentVal - a >= 0)
      {
        answer = std::min(answer, currentVal - a);
      }
    }
    b++;
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  //freopen("input.txt", "r", stdin);
  while(ReadData())
  {
    Solve();
    WriteData();
  }
  return 0;
}