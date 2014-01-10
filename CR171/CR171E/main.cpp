#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  char str[1000005];
  scanf("%s", &str);
  int len = strlen(str);
  int zero = 0;
  for(int i = 0; i < len; i++)
  {
    if(str[i] == '0')
      zero++;
  }
  int ones = len - zero;
  if(ones == 1)
  {
    printf("1");
  }
  else if(ones == len)
  {
    printf("2");
  }
  else if(ones > zero)
  {
    int add = 0;
    if(str[len - 1] == '1' && str[len - 2] == '0')
    {
      add++;
    }
    printf("%d", 1 + zero + add);
  }
  else
  {
    printf("%d", ones);
  }
  return 0;
}
