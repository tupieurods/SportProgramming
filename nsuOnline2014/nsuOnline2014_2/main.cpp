#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[109];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int w, h;
  scanf("%d %d%*c", &h, &w);
  int _x = -1, _y = -1;
  for(int i = 0; i < h; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < w; j++)
    {
      if(str[j] == '#')
      {
        _x = std::max(_x, j);
        _y = i;
      }
    }
  }
  _x++;
  _y++;
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &h, &w);
    if(_x <= w && _y <= h)
    {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  return 0;
}