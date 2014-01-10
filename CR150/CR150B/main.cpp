#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>

using namespace std;

int anwser = 0;
int n;

bool validateNumber(int number)
{
  bool data[10];
  memset(data, 0, sizeof(bool) * 10);
  int count = 0;
  while(number != 0)
  {
    if(data[number % 10] == false)
    {
      data[number % 10] = true;
      count++;
      if(count == 3)
        return false;
    }
    number /= 10;
  }
  return true;
}

void dfs(int value)
{
  //printf("%d\n", value);
  if((value > 0) && (value <= n))
    anwser++;
  for(int i = 0; i < 10; i++)
  {
    if(value * 10 + i > 0)
      if(validateNumber(value * 10 + i))
        dfs(value * 10 + i);
  }
}

int main()
{
  scanf("%d", &n);
  dfs(0);
  printf("%d", anwser);
  return 0;
}
