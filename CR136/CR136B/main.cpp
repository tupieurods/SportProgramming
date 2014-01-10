#include <stdio.h>
#include <math.h>

using namespace std;

int number[9];

bool check(int value)
{
  while(value != 0)
    {
      if(number[value % 10] != 0)
        return true;
      value /= 10;
    }
  return false;
}

int main()
{
  int x;
  scanf("%d", &x);
  for(int i = 0; i < 10; i++)
  {
    number[i] = 0;
  }
  int tmpX = x;
  while(tmpX != 0)
  {
    number[tmpX % 10]++;
    tmpX /= 10;
  }
  int count = 0;
  for(int i = 1; i * i <= x; i++)
  {
    if(x % i == 0)
    {
      if(check(i))
      {
        count++;
      }
      if(i * i != x)
      {
        if(check(x / i))
        {
          count++;
        }
      }
    }
  }
  printf("%d", count);
  return 0;
}
