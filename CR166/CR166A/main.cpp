#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  bool numbers[10];
  for(int i = n + 1; i < 9100; i++)
  {
    memset(numbers, 0, sizeof(bool) * 10);
    int current = i;
    bool flag = true;
    while(current != 0)
    {
      if(numbers[current % 10])
      {
        flag = false;
        break;
      }
      numbers[current % 10] = true;
      current /= 10;
    }
    if(flag)
    {
      printf("%d", i);
      break;
    }
  }
  return 0;
}
