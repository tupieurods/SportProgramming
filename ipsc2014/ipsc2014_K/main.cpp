#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char table[150][150];

int main()
{
  int QWE = 1;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int w, h;
  scanf("%d %d%*c", &w, &h);
  memset(table, 0, sizeof(table));
  for(int i = 0; i < w; i++)
  {
    scanf("%s%*c", table[i]);
  }
  int cnt = 0;
  scanf("%d", &cnt);
  char str[109];
  for(int i = 0; i < cnt; i++)
  {
    int xp, yp;
    scanf("%d %d %s%*c", &yp, &xp, str);
    int len = strlen(str);
    for(int j = 0; j < len; j++)
    {
      if(table[yp][xp + j] == '.')
      {
        throw;
      }
      if(table[yp][xp + j] != '#' && table[yp][xp + j] != str[j])
      {
        throw;
      }
      table[yp][xp + j] = str[j];
    }
  }
  scanf("%d", &cnt);
  for(int i = 0; i < cnt; i++)
  {
    int xp, yp;
    scanf("%d %d %s%*c", &yp, &xp, str);
    int len = strlen(str);
    for(int j = 0; j < len; j++)
    {
      if(table[yp + j][xp] == '.')
      {
        throw;
        goto shit;
      }
      if(table[yp + j][xp] != '#' && table[yp + j][xp] != str[j])
      {
        throw;
        goto shit;
      }
      table[yp + j][xp] = str[j];
    }
  }
  shit:
  for(int i = 0; i < w; i++)
  {
    printf("%s\n", table[i]);
  }
  return 0;
}