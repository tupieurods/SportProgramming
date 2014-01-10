#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d\n", &n);
  int x = 0;
  char str[5];
  for(int i = 0; i < n; i++)
  {
    scanf("%s", str);
    int addV = 1;
    for(int j = 0; j < 3; j++)
    {
      if(str[j] == '-')
      {
        addV = -1;
        break;
      }
    }
    x += addV;
  }
  printf("%d\n", x);
  return 0;
}
