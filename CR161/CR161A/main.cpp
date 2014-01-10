#include <stdio.h>
#include <cmath>

using namespace std;

int abs(int value)
{
  return value >=0 ? value : -value;
}

int main()
{
  for(int i = 1; i < 6; i++)
  {
    for(int j = 1; j < 6; j++)
    {
      int tmp;
      scanf("%d", &tmp);
      if(tmp == 1)
      {
        printf("%d", abs(3 - i) + abs(3 - j));
        return 0;
      }
    }
  }
  return 0;
}
