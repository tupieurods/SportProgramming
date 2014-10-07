#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char strs[3][19]=
{
  "qwertyuiop",
  "asdfghjkl;",
  "zxcvbnm,./"
};

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  char str[109];
  scanf("%s%*c", str);
  int d = str[0] == 'R' ? -1 : +1;
  scanf("%s%*c", str);
  int l = strlen(str);
  for(int i = 0; i < l; i++)
  {
    bool flag = false;
    for(int j = 0; j < 3; j++)
    {
      for(int k = 0; k < 10; k++)
      {
        if(str[i] == strs[j][k])
        {
          str[i] = strs[j][k + d];
          flag = true;
          break;
        }
      }
      if(flag)
      {
        break;
      }
    }
  }
  printf("%s\n", str);
  return 0;
}